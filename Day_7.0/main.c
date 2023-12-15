#include "day7.h"

#define N_HANDS		5000
#define HAND_LEN	6
#define BID_IDX		6

char	*parse_line(char *line, int *bid);
char	*get_hand(char *line);
void	bubble_sort(char **hands, int n);	
void	swap(char *a, char *b);

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
	printf(URED"Hands before sorting:\n\n"CRESET);
	while ((++i < N_HANDS) && (bids[i] != 0))
		printf("\tHand: %s\tBid: %d\n", hands[i], bids[i]);
	printf("\n");

	printf(YEL SEPLNG "\n" CRESET);
	/* Sort Hands by Strength */
	bubble_sort((char **)hands, N_HANDS);	
	/* Print sorted hands */
	i = -1;
	printf(UGRN"Hands after sorting:\n\n"CRESET);
	while ((++i < N_HANDS) && (bids[i] != 0))
		printf("\tHand: %s\tBid: %d\n", hands[i], bids[i]);
	printf("\n");


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
	*bid = atoi(line + BID_IDX);

	return (hand);
}

/* Get Hand from line
* */
char	*get_hand(char *line)
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

void	bubble_sort(char **arr, int n)
{
	int		i;
	int		j;
	int		swapped;

	i = 0;
	swapped = 0;
	while (i < n)
	{
		j = 0;
		swapped = 0;
		while (j < (HAND_LEN - 1))
		{
			if (arr[i][j] > arr[i + 1][j])
			{
				swap(arr[i], arr[i + 1]);
				swapped = 1;
				break;

			}
			++j;
		}
		if (!swapped)
			break;
		++i;
	}
}

/* Swap two values
 * */
void	swap(char *a, char *b)
{
	char	*tmp;

	tmp = a;
	a = b;
	b = tmp;
}
