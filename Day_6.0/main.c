#include "day6.h"

void	get_time(char *line, int **time);
void	get_distance(char *line, int **distance);

int		main(void)
{
	char	*line;
	int		*time;
	int		*distance;
	int		fd;

	printf("Day 6.0\n");
	printf(SEPLNG);

	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	/* Read time and distance from file */
	time = NULL;
	distance = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		if (!time)
			get_time(line, &time);
		else
			get_distance(line, &distance);
		free(line);
	}
	close(fd);
	
	/* Print parsed data */
	printf(SEP);
	if (time)
	{
		printf("Time: %d\n", *time);
		free(time);
	}
	if (distance)
	{
		printf("Distance: %d\n", *distance);
		free(distance);
	}

	printf(SEPLNG);
	return (0);	
}

/* Get time from first line
 * */
void	get_time(char *line, int **time)
{
	(void)line;
	(void)time;
}

/* Get distance from second line
 * */
void	get_distance(char *line, int **distance)
{
	(void)line;
	(void)distance;
}
