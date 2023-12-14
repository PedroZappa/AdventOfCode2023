#include "day6.h"
#include <ctype.h>

int		get_time(char *line);
int		get_distance(char *line);

int		main(void)
{
	char	*time;
	char	*distance;
	int		time_num[3]		= { 0 };
	int		distance_num[3] = { 0 };
	int		fd;
	int		i;

	printf("Day 6.0\n");
	printf(SEPLNG);

	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	/* Read time from file */
	time = get_next_line(fd);
	i = 0;
	while (i < 3)
	{
		time_num[i] = get_time(time);
		++i;
	}
	free(time);

	/* Read distance from file */
	distance = get_next_line(fd);
	i = 0;
	while (i < 3)
	{
		distance_num[i] = get_distance(distance);
		++i;
	}
	free(distance);

	close(fd);
	
	/* Print parsed data */
	printf(SEP);
	printf("Time: ");
	for (i = 0; i < 3; ++i)
		printf("%d ", time_num[i]);
	printf("\n");
	printf("Distance: ");
	for (i = 0; i < 3; ++i)
		printf("%d ", distance_num[i]);
	printf("\n");

	printf(SEPLNG);
	return (0);	
}

/* Get time from first line
 * */
int	get_time(char *line)
{
	static char	*local_line;
	int			fixlen;
	int			time;

	if (!local_line)
		local_line = line;
	fixlen = 0;
	time = 0;
	while (local_line)
	{
		if (isdigit(*local_line))
		{
			time = atoi(local_line);
			if (time > 9)
				fixlen = 1;
			else if (time > 99)
				fixlen = 2;
			local_line += fixlen;
		}
		++local_line;
		if (time != 0)
			return (time);
	}
	return (0);
}

/* Get distance from second line
 * */
int	get_distance(char *line)
{
	static char	*local_line;
	int			fixlen;
	int			distance;

	if (!local_line)
		local_line = line;
	fixlen = 0;
	distance = 0;
	while (local_line)
	{
		if (isdigit(*local_line))
		{
			distance = atoi(local_line);
			if (distance > 9)
				fixlen = 1;
			else if (distance > 99)
				fixlen = 2;
			local_line += fixlen;
		}
		++local_line;
		if (distance != 0)
			return (distance);
	}

	return (0);
}
