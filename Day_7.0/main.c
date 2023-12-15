#include "day7.h"

char	*parse_line(char *line, int *bid);
char	*get_hand(char *line);
int		*get_types(char **line);
void	sort(char **hands, int n);	
void	swap(char *a[], char *b[]);
int		compare_cards(char *a, char *b, int i);

int		main(void)
{
	char	*line;
	char	*hand;
	char	*hands[N_HANDS]		= { 0 };
	int		bids[N_HANDS]		= { 0 };
	int		*types;
	int		winnings[N_HANDS]	= { 0 };
	int		fd;
	int		i;

	printf(HBLU"Day 7.0"CRESET"\n");
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
	printf(YEL SEPLNG CRESET);

	/* Evaluate Hand Types */
	types = get_types(hands);
	/* Print Hand Types */
	printf(UMAG"Hand Types:\n\n"CRESET);
	i = -1;
	// while ((++i < N_HANDS) && (bids[i] != 0))
	// 	printf("\tHand: %s\tType: %d\n", hands[i], types[i]);
	(void)types;
	printf("\n");
	printf(YEL SEPLNG CRESET);

	/* Sort Hands by Strength */
	sort((char **)hands, N_HANDS);	
	/* Print sorted hands */
	printf(UGRN"Hands after sorting:\n\n"CRESET);
	i = -1;
	while ((++i < N_HANDS) && (bids[i] != 0))
		printf("\tHand: %s\tBid: %d\n", hands[i], bids[i]);
	printf("\n");

	printf(GRN SEPLNG CRESET);

	/* Calculate Winnings */
	(void)winnings;

	
	/* Free types */
	free(types);
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
	while (line[i] && (i < HAND_LEN))
	{
		hand[i] = line[i];
		++i;
	}
	hand[i] = '\0';
	return (hand);
}


int		*get_types(char **line)
{
	int		*types = calloc(sizeof(int) * N_HANDS, sizeof(int));
	int		i = 0;
	int		n = 0;
	int		two = 0;
	int		three = 0;
	int		four = 0;
	int		five = 0;
	int		six = 0;
	int		seven = 0;
	int		eight = 0;
	int		nine = 0;
	int		t = 0;
	int		j = 0;
	int		q = 0;
	int		k = 0;
	int		a = 0;

	i = 0;
	while (line[i] && (i < N_HANDS))
	{
		j = 0;
		two = 0;
		three = 0;
		four = 0;
		five = 0;
		six = 0;
		seven = 0;
		eight = 0;
		nine = 0;
		t = 0;
		j = 0;
		q = 0;
		k = 0;
		a = 0;
		while (line[i][n] && (j < HAND_LEN))
		{
			switch (line[i][n])
			{
				case '2':
					++two;
					break;
				case '3':
					++three;
					break;
				case '4':
					++four;
					break;
				case '5':
					++five;
					break;
				case '6':
					++six;
					break;
				case '7':
					++seven;
					break;
				case '8':
					++eight;
					break;
				case '9':
					++nine;
					break;
				case 'T':
					++t;
					break;
				case 'J':
					++j;
					break;
				case 'Q':
					++q;
					break;
				case 'K':
					++k;
					break;
				case 'A':
					++a;
					break;
			}
			/* Check Type */
			if ((two == 5) || (three == 5) || (four == 5) || (five == 5) || 
				(six == 5) || (seven == 5) || (eight == 5) || (nine == 5) || 
				(t == 5) || (j == 5) || (q == 5) || (k == 5) || (a == 5))
				types[i] = FIVE_OA_KIND;
			else if ((two == 4) || (three == 4) || (four == 4) || (five == 4) ||
					(six == 4) || (seven == 4) || (eight == 4) || (nine == 4) ||
					(t == 4) || (j == 4) || (q == 4) || (k == 4) || (a == 4))
				types[i] = FOUR_OA_KIND;
			else if ((two == 3) || (three == 3) || (four == 3) || (five == 3) ||
					(six == 3) || (seven == 3) || (eight == 3) || (nine == 3) ||
					(t == 3) || (j == 3) || (q == 3) || (k == 3) || (a == 3))
				types[i] = THREE_OA_KIND;
			else if ((two == 2) || (three == 2) || (four == 2) || (five == 2) ||
					(six == 2) || (seven == 2) || (eight == 2) || (nine == 2) ||
					(t == 2) || (j == 2) || (q == 2) || (k == 2) || (a == 2))
				types[i] = TWO_PAIR;
				else

			++n;
		}
		printf("%s\n", line[i]);
		++i;
	}
	return (NULL);
}

void	sort(char **arr, int n)
{
	int		i;
	int		j;
	int		check_card;

	i = 0;
	while (arr[i] && (i < n))
	{
		j = 0;
		check_card = 0;
		while ((j < HAND_LEN) && (arr[i + 1] != NULL))
		{
			check_card = compare_cards(arr[i], arr[i + 1], j);
			if (check_card == 1)
			{
				swap(&arr[i], &arr[i + 1]);
			}
			else if (check_card == 0)
				++j;
			else
				break;
		}
		++i;
	}
}

/*	Compare a letter between two Hands using card_pow ruler
 *	*/
int		compare_cards(char *hand_a, char *hand_b, int i)
{
	char	*card_pow = "23456789TJQKA";
	char	card_a = *(hand_a + i);
	char	card_b = *(hand_b + i);
	int		a_value;
	int		b_value;
	int		n;

	/* ID current letter */
	n = 0;
	a_value = 0;
	b_value = 0;
	while (n < N_POW)
	{
		if (card_a == card_pow[n]) 
			a_value = n;
		if (card_b == card_pow[n]) 
			b_value = n;
		if ((a_value != 0) && (b_value != 0))
			break;
		++n;
	}
	if (a_value > b_value)
		return (1);
	if (a_value == b_value)
		return (0);
	else
		return (-1);
}

/*	Swap two values
 *	*/
void	swap(char *a[], char *b[])
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_hands(char **hands, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%s\n", hands[i]);
		++i;
	}
}
