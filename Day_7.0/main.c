#include "day7.h"

#define N_HANDS		1000
#define HAND_LEN	5
#define BID_IDX		6

void	parse_line(char *line, char *hand, int *bid);
char	*get_hand(char *line);

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
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		parse_line(line, &hands[i], &bids[i]);
		++i;
	}
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
void	parse_line(char *line, char *hand, int *bid)
{
	*hand = *get_hand(line);
	*bid = atoi(line + BID_IDX);
}

char		*get_hand(char *line)
{
	char	*hand;
	int		i;

	hand = malloc(sizeof(char) * HAND_LEN);
	if (!hand)
		return (NULL);
	i = 0;
	while (line[i] && (i < HAND_LEN))
	{
		hand[i] = line[i];
		++i;
	}
	hand[i] = '\0';
	return (hand);
}

