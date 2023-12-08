#include "day4.h"

int main(void)
{
	char	*line;
	int		i;
	int		n;
	int		fd;
	int		len;					/* Line length */
	int		EOL;					/* End of List */
	int		win_i;					/* Index for win_nums */
	int		num_i;					/* Index for nums */
	int		lenfix = 0;					/* Flag to adjust len if num > 9 */
	int		win_nums[11]	= { 0 };	/* Card Index + Winning numbers */
	int		nums[25]		= { 0 };	/* Card numbers */
	int		card_points;
	int		total_points;

	fd = open("files/cards.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	total_points = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		/* Parse line */
		EOL = 0;
		len = 0;
		win_i = 0;
		num_i = 0;
		while (line[len] != '\0')
		{
			if (isdigit(line[len]) || line[len] == '|')
			{
				if (isdigit(line[len]) && !EOL)
				{
					win_nums[win_i] = ft_atoi(line + len);
					if (win_nums[win_i] > 9)
						lenfix = 1;
					++win_i;
				}
				if (line[len] == '|')
					EOL = 1;
				if (isdigit(line[len]) && EOL)
				{
					nums[num_i] = ft_atoi(line + len);
					if (nums[num_i] > 9)
						lenfix = 1;
					++num_i;
				}
			}
			if (lenfix)
			{
				++len;
				lenfix = 0;
			}
			++len;
		}

		/* Print parsed winning numbers */
		printf(UWHT"Card: %d\n"CRESET, win_nums[0]);
		printf(BHYEL"Winning numbers:\n"CRESET);
		for (int i = 0; i < win_i; ++i)
			printf("%d ", win_nums[i]);
		printf("\n");
		/* Print parsed card numbers */
		printf(BHGRN"Card numbers:\n"CRESET);
		for (int i = 0; i < num_i; ++i)
			printf("%d ", nums[i]);
		printf("\n");
		printf(SEP);

		/* Check for winning numbers in the numbers I have 
		* Canculate the card_points per card
		* */
		i = 1;		/* We start at 1 to ignore the card number */
		n = 0;
		card_points = 0;
		while (i < win_i)
		{
			while (n < num_i)
			{
				if (win_nums[i] == nums[n])
				{
					if (card_points == 0)
					{
						card_points = 1;
						break;
					}
					else
					{
						card_points *= 2;
						break;
					}
				}
				++n;
			}
			n = 0;
			++i;
		}

		/* Print  */
		printf("Card %d Points: %d\n", i, card_points);
		printf(SEPLONG);
		
		total_points += card_points;
		card_points = 0;
		free(line);
	}	
	close(fd);

	printf("Total points: %d\n", total_points);

	return 0;
}
