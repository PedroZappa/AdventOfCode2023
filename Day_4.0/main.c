#include "day4.h"

void parse_line(char *line);

int main(void)
{
	int		fd;
	char	*line;

	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	while ((line = get_next_line(fd)) != NULL)
	{
		/* Parse line */
		parse_line(line);


		free(line);
	}	
	close(fd);

	return 0;
}

void parse_line(char *line)
{
	int		len = 0;					/* Line length */
	int		EOL = 0;					/* End of List */
	int		win_i = 0;					/* Index for win_nums */
	int		num_i = 0;					/* Index for nums */
	int		lenfix = 0;					/* Flag to adjust len if num > 9 */
	int		win_nums[11]	= { 0 };	/* Card Index + Winning numbers */
	int		nums[25]		= { 0 };	/* Card numbers */
	
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

	/* Print winning numbers */
	printf("Card: %d\n", win_nums[0]);
	printf("Winning numbers:\n");
	for (int i = 0; i < win_i; ++i)
		printf("%d ", win_nums[i]);
	printf("\n");

	/* Print card numbers */
	printf("Card numbers: ");
	for (int i = 0; i < num_i; ++i)
		printf("%d ", nums[i]);
	printf("\n");

	printf(SEP);

	return ;
}
