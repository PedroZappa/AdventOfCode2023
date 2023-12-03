#include "day1.h"

int		main(void)
{
	t_calib_val	*read_vals;
	char		*line;
	int			*vals_list;
	int			n_lines;
	int			sum;
	int			fd;
	int			i;

	fd = open("calibration-doc.txt", O_RDONLY);
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
	fd = open("calibration-doc.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open() failed");
		return 1;
	}
	// Extract Values
	i = 0;
	vals_list = malloc(sizeof(int) * n_lines);
	while ((line = get_next_line(fd)) != NULL)
	{
		// printf("%s", line);
		read_vals = malloc(sizeof(t_calib_val));
		*read_vals = get_calib_val(line);
		vals_list[i] = read_vals->calib_val;
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

}

t_calib_val		get_calib_val(char *line)
{
	t_calib_val	calib_val;

	calib_val.first_dig = -1;
	calib_val.last_dig = -1;
	calib_val.calib_val = 0;
	while (*line) 
	{
		if (*line >= '0' && *line <= '9')
		{
			if (calib_val.first_dig == -1)
				calib_val.first_dig = *line - '0';
			calib_val.last_dig = *line - '0';
		}
		++line;
	}
	calib_val.calib_val = (calib_val.first_dig * 10) + calib_val.last_dig;
	return (calib_val);
}
