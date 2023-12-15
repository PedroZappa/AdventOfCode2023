#include "day7.h"

#define N_HANDS		1000
#define HAND_LEN	6
#define BID_IDX		6

char	*parse_line(char *line, int *bid);
char	*get_hand(char *line);

int		main(void)
{
	char	*line;
	char	*hand;
	char	*hands[N_HANDS]		= { 0 };
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
	hand = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		hand = parse_line(line, &bids[i]);
		hands[i] = hand;
		++i;
	}
	close(fd);
	/* Print Results */
	i = -1;
	while ((++i < N_HANDS) && (bids[i] != 0))
		printf("Hand: %s\tBid: %d\n", hands[i], bids[i]);

	/* Sort Hands by Strength */
	

	/* Calculate Winnings */
	(void)winnings;

	
	/* Free hands */

	printf(SEPLNG);
	return (0);
}

/* Parse Hand and Bid from each line
 * */
char	*parse_line(char *line, int *bid)
{
	char	*hand;

	hand = get_hand(line);
	printf(YEL"parse_line(): Hand: %s\n"CRESET, hand);
	*bid = atoi(line + BID_IDX);

	return (hand);
}

char		*get_hand(char *line)
{
	char	*hand;
	int		i;

	hand = malloc(sizeof(char) * HAND_LEN);
	if (!hand)
		return (NULL);
	i = 0;
	while (line[i] && (i < HAND_LEN-1))
	{
		hand[i] = line[i];
		++i;
	}
	hand[i] = '\0';
	return (hand);
}

