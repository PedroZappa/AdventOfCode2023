#include "day6.h"
#include <ctype.h>

#define		N_RACES		4

int		get_time(char *line);
int		get_distance(char *line);
int		get_n_ways(int time, int record_dist);

int		main(void)
{
	char	*time;
	char	*distance;
	int		time_num[N_RACES]		= { 0 };
	int		distance_num[N_RACES]	= { 0 };
	int		n_ways[N_RACES]			= { 0 };
	int		fd;
	int		i;

	printf("Day 6.0\n");
	printf(SEPLNG);

	fd = open("files/races.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	/* Read time from file */
	time = get_next_line(fd);
	i = -1;
	while (++i < N_RACES)
		time_num[i] = get_time(time);
	free(time);

	/* Read distance from file */
	distance = get_next_line(fd);
	i = -1;
	while (++i < N_RACES)
		distance_num[i] = get_distance(distance);
	free(distance);

	close(fd);
	
	/* Print parsed data */
	printf(SEP);
	printf("Time: ");
	for (i = 0; i < N_RACES; ++i)
		printf("%d ", time_num[i]);
	printf("\n");
	printf("Distance: ");
	for (i = 0; i < N_RACES; ++i)
		printf("%d ", distance_num[i]);
	printf("\n");
	printf(SEP);

	/* Calculate the number of ways you can beat the record */
	i = -1;
	while (++i < N_RACES)
		n_ways[i] = get_n_ways(time_num[i], distance_num[i]);

	printf("Number of ways: ");
	for (i = 0; i <	N_RACES; ++i)
		printf("%d ", n_ways[i]);
	printf("\n");

	int	total; 

	i = -1;
	total = 1;
	while (++i < N_RACES)
		total *= n_ways[i];
	printf("Total number of ways: %d\n", total);


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
			else if (time > 999)
				fixlen = 3;
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

/* Get the number of ways you can beat the race record 
 *		time: total race time in miliseconds
 *		record_dist: record distance in milimiters
 * */
int		get_n_ways(int time, int record_dist)
{
	int		n_ways;
	int		press_time;
	int		travel_time;
	int		travel_dist;
	
	n_ways = 0;
	press_time = 0;
	travel_dist = 0;
	while (press_time < time)
	{
		travel_time = time - press_time;
		travel_dist = press_time * travel_time;
		if (travel_dist > record_dist)
			++n_ways;
		++press_time;
	}

	return (n_ways);
}
