#include "day6.h"
#include <ctype.h>

#define		N_RACES		1

long long			get_time(char *line);
long long			get_distance(char *line);
long long			get_n_ways(long long time, long long record_dist);
long long			numlen(long long num);

int		main(void)
{
	char			*time;
	char			*distance;
	long long		time_num[N_RACES]		= { 0 };
	long long		distance_num[N_RACES]	= { 0 };
	long long		n_ways[N_RACES]			= { 0 };
	long long		fd;
	long long		i;

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
		printf("%lld ", time_num[i]);
	printf("\n");
	printf("Distance: ");
	for (i = 0; i < N_RACES; ++i)
		printf("%lld ", distance_num[i]);
	printf("\n");
	printf(SEP);

	/* Calculate the number of ways you can beat the record */
	i = -1;
	while (++i < N_RACES)
		n_ways[i] = get_n_ways(time_num[i], distance_num[i]);

	printf("Number of ways: ");
	for (i = 0; i <	N_RACES; ++i)
		printf("%lld ", n_ways[i]);
	printf("\n");

	long long	total; 

	i = -1;
	total = 1;
	while (++i < N_RACES)
		total *= n_ways[i];
	printf("Total number of ways: %lld\n", total);


	printf(SEPLNG);
	return (0);	
}

/* Get time from first line
 * */
long long	get_time(char *line)
{
	static char	*local_line;
	long long			time;

	if (!local_line)
		local_line = line;
	time = 0;
	while (local_line)
	{
		if (isdigit(*local_line))
		{
			time = atoi(local_line);
			local_line += numlen(time);
		}
		++local_line;
		if (time != 0)
			return (time);
	}
	return (0);
}

/* Get distance from second line
 * */
long long	get_distance(char *line)
{
	static char	*local_line;
	long long			distance;

	if (!local_line)
		local_line = line;
	distance = 0;
	while (local_line)
	{
		if (isdigit(*local_line))
		{
			distance = atoll(local_line);
			local_line += numlen(distance);
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
long long		get_n_ways(long long time, long long record_dist)
{
	long long		n_ways;
	long long		press_time;
	long long		travel_time;
	long long		travel_dist;
	
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

long long		numlen(long long num)
{
	long long		len;
	
	len = 1;
	while (num > 9)
	{
		num /= 10;
		++len;
	}
	return (len);
}





