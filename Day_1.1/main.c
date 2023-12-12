#include "day1.h"
#include <ctype.h>

t_calib_val		get_calib_val(char *line);
int				getnum(char *line, t_calib_val *calib_val, int *got_first, int *got_last);
int				is_strnum(char *line);
int				getskip(char *line, t_calib_val *calib_val, int *got_first);
int				numstrlen(int num);
int				strtoi(char *str);

int		main(void)
{
	t_calib_val	*read_vals;
	char		*line;
	int			*vals_list;
	int			n_lines;
	int			sum;
	int			fd;
	int			i;

	// fd = open("files/calibration-doc.txt", O_RDONLY);
	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open() failed");
		return 1;
	}
	// Count number of lines to get lenght of `vals_list`
	n_lines = 0;
	while (get_next_line(fd) != NULL)
		++n_lines;	
	close(fd);
	// fd = open("files/calibration-doc.txt", O_RDONLY);
	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open() failed");
		return 1;
	}
	// Extract Values
	i = 0;
	read_vals = NULL;
	vals_list = malloc(sizeof(int) * n_lines);
	if (!vals_list)
		return 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		read_vals = malloc(sizeof(t_calib_val));
		if (!read_vals)
			return 1;
		*read_vals = get_calib_val(line);
		vals_list[i] = read_vals->calib_val;
		printf("Calibration value %d: %d\n", (i+1), read_vals->calib_val);
		free(read_vals);
		free(line);
		++i;
	}
	close(fd);
	// Sum values
	sum = 0;
	i = -1;
	while (vals_list[++i])
		sum += vals_list[i];
	printf("The sum of all calibration values is: \n");
	printf("\t%d\n", sum);
	free(vals_list);

	return 0;
}


/* Extract Calibration Values 
 * */
t_calib_val		get_calib_val(char *line)
{
	t_calib_val	*calib_val;
	int			got_first;
	int			got_last;

	calib_val = malloc(sizeof(t_calib_val));
	calib_val->first_dig = -1;
	calib_val->last_dig = -1;
	calib_val->calib_val = 0;
	got_first = 0;
	while (*line) 
	{
		got_last = 0;
		if (*line >= '0' && *line <= '9')
		{
			if (calib_val->first_dig == -1)
			{
				calib_val->first_dig = *line - '0';
				got_first = 1;
			}
			calib_val->last_dig = *line - '0';
			++line;
		}
		else if ((*line >= 'a' && *line <= 'z') || (*line >= 'A' && *line <= 'Z'))
			line += getnum(line, calib_val, &got_first, &got_last);	
		else if (*line == '\n')
		{
			++line;
			break ;
		}
	}
	calib_val->calib_val = (calib_val->first_dig * 10) + calib_val->last_dig;
	return (*calib_val);
}

int	getnum(char *line, t_calib_val *calib_val, int *got_first, int *got_last)
{
	if (*got_first == 0)
	{
		calib_val->first_dig = is_strnum(line);
		if (calib_val->first_dig == 0)
			return (getskip(line, calib_val, got_first));	
		else
		{
			*got_first = 1;
			return (numstrlen(calib_val->first_dig));
		}
	}
	else if (*got_last == 0)
	{
		if (is_strnum(line) > 0)
			calib_val->last_dig = is_strnum(line);
		if (calib_val->last_dig <= 0)
		{
			calib_val->last_dig = is_strnum(line);
			return (getskip(line, calib_val, got_first));
		}
		else
		{
			*got_last = 1;
			return (numstrlen(calib_val->last_dig));
		}
	}
	else
	++line;
	if (*line == '\n')
		++line;
	return (0);
}

/* Look for spelled out digit 
 * */
int	is_strnum(char *line)
{
	int		n_strs;
	int		slen;
	int		num;
	int		i;
	char	*numstr[] = {	
		"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" 
	};

	i = 1;
	num = 0;
	slen = 0;
	n_strs = sizeof(numstr) / sizeof(numstr[0]);
	while (i < n_strs)
	{
		slen = strlen(numstr[i]);
		if ((num = strncmp(line, numstr[i], slen)) == 0)
			return (strtoi(numstr[i]));		/* Returns found digit */
		++i;
	}
	return (0);
}

/* If no spelled out digit was found get length of chars before 
* next digit or spelled out digit 
* */
int	getskip(char *line, t_calib_val *calib_val, int *got_first)
{
	int		n_strs;
	int		slen;
	int		num;
	int		i;
	int		j;
	int		skip;
	int		return_skip;
	char	*numstr[] = {	
		"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" 
	};
	i = 1;
	j = 0;
	skip = 0;
	return_skip = 0;
	slen = strlen(numstr[i]);
	n_strs = sizeof(numstr) / sizeof(numstr[0]);
	while (i < n_strs)
	{
		while (*line && isalpha(*line) && (j < slen-1))
		{
			if ((num = strncmp(line, numstr[i], slen)) != 0)
				++skip;	
			else if ((num = strncmp(line, numstr[i], slen)) == 0)
			{
				if (!got_first)	
					calib_val->first_dig = strtoi(numstr[i]);
				else
					calib_val->last_dig = strtoi(numstr[i]);
				return (slen + i);
			}
			if (num == 0)
				return (skip);
			++line;
			++j;
		}
		line -= skip;
		return_skip = skip;
		skip = 0;
		j = 0;
		++i;
		if (i < 10)
			slen = strlen(numstr[i]);
	}
	return (return_skip);
}

int		numstrlen(int num)
{
	int		len;
	char	*numstr;
	char *numstrs[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	len = 0;
	numstr = NULL;
	numstr = numstrs[num];
	len = strlen(numstr);
	return (len);
}

int		strtoi(char *str)
{
	if(strcmp(str, "zero") == 0) 
		return 0;
	else if(strcmp(str, "one") == 0) 
		return 1;
	else if(strcmp(str, "two") == 0) 
		return 2;
	else if(strcmp(str, "three") == 0) 
		return 3;
	else if(strcmp(str, "four") == 0) 
		return 4;
	else if(strcmp(str, "five") == 0) 
		return 5;
	else if(strcmp(str, "six") == 0) 
		return 6;
	else if(strcmp(str, "seven") == 0) 
		return 7;
	else if(strcmp(str, "eight") == 0) 
		return 8;
	else if(strcmp(str, "nine") == 0) 
		return 9;
	else return -1;
}
