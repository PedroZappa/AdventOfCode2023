#include "day7.h"

#define N_HANDS		1000

void	parse_line(char *line, char *hands, int *bids, int i);
char		*get_hand(char *line);

int		main(void)
{
	char	*line;
	char	hands[N_HANDS]		= { 0 };
	int		bids[N_HANDS]		= { 0 };
	int		winnings[N_HANDS]	= { 0 };
	int		fd;
	int		i;

	printf("Day 7.0\n");
	printf(SEPLNG);

	/* Open File */
	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open() failed: ");
		return (1);
	}
	/* Read File & Parse Data */
	i = -1;
	while ((line = get_next_line(fd)) != NULL)
		parse_line(line, hands, bids, ++i);
	/* Print Results */
	i = -1;
	while ((++i < N_HANDS) && (hands[i] != 0))
		printf("Hand: %c - Bid: %d\n", hands[i], bids[i]);

	/* Sort Hands by Strength */
	

	/* Calculate Winnings */
	(void)winnings;

	close(fd);
	printf(SEPLNG);
	return (0);
}

/* Parse Hand and Bid from each line
 * */
void	parse_line(char *line, char *hands, int *bids, int i)
{

	hands[i]	= *get_hand(line);
	bids[i]		= atoi(line+6);
}

char		*get_hand(char *line)
{
	return (line);
}

