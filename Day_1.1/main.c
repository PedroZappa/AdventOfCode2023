#include "day1.h"

t_calib_val		get_calib_val(char *line);
int				is_strnum(char *line);
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
	// Count number of lines
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


t_calib_val		get_calib_val(char *line)
{
	t_calib_val	calib_val;
	// int			len;

	calib_val.first_dig = -1;
	calib_val.last_dig = -1;
	calib_val.calib_val = 0;
	// len = 0;
	while (*line) 
	{
		if (*line >= '0' && *line <= '9')
		{
			if (calib_val.first_dig == -1)
				calib_val.first_dig = *line - '0';
			calib_val.last_dig = *line - '0';
			++line;
		}
		else if ((*line >= 'a' && *line <= 'z') || (*line >= 'A' && *line <= 'Z'))
		{
			if (calib_val.first_dig == -1)
			{
				calib_val.first_dig = is_strnum(line);
				line += numstrlen(calib_val.first_dig);
			}	
			else if (calib_val.last_dig == -1)
			{
				calib_val.last_dig = is_strnum(line);
				line += numstrlen(calib_val.last_dig);
			}
			else
			{
				calib_val.last_dig = is_strnum(line);
				line += numstrlen(calib_val.last_dig) - 1;
			}
			if (*line == '\n')
			++line;
		}
	}
	calib_val.calib_val = (calib_val.first_dig * 10) + calib_val.last_dig;
	return (calib_val);
}

int	is_strnum(char *line)
{
	int		n_strs;
	int		slen;
	int		num;
	int		i;
	int		skip;
	char	*numstr[] = {	
		"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" 
	};

	n_strs = sizeof(numstr) / sizeof(numstr[0]);
	i = 1;
	num = 0;
	slen = 0;
	while (i < n_strs)
	{
		slen = strlen(numstr[i]);
		if ((num = strncmp(line, numstr[i], slen)) == 0)
			return (strtoi(numstr[i]));
		++i;
	}
	/* If no spelled out digit was found get lenght of chars before 
	 * next digit or spelled out digit */
	i = 1;
	skip = 0;
	slen = strlen(numstr[i]);
	while (i < n_strs)
	{
		while ((num = strncmp(line, numstr[i], slen)) != 0)
		{
			++skip;
			break ;

		}
		if (num == 0)
			return (skip);
		++i;
		++line;
		slen = strlen(numstr[i]);

	}
	return (skip);
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
