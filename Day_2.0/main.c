#include "day2.h"

void	parse_game(char *line, t_game **game);
t_game	*getlastgame(t_game *games_list);
t_round	*getlastround(t_round *rounds_list);

int main(void)
{
	int		fd;
	int		n_games;
	int		sum;
	char	*line;
	t_game	*games_list;

	games_list = NULL;
	/* Open file for counting number of lines */
	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	/* Get number of lines in the file */
	n_games = 0;
	while ((line = get_next_line(fd)) != NULL)
		++n_games;
	/* Close the file */
	close(fd);

	/* Open the file for Parsing */
	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	/* Parse the file */
	while ((line = get_next_line(fd)) != NULL)
	{
		/* Parse the line into node */
		parse_game(line, &games_list);
		/* Free the line */
		free(line);
	}
	/* Close the file */
	close(fd);

	/* Loop through linked list and sum up valid scores */
	sum = 0;

	/* Dbg */
	/* Print linked list */
	printf("Games List:\n");
	while (games_list)
	{
		printf("%d\n", games_list->id);
		printf("Red : %d\nGreen : %d\nBlue : %d\n", 
			games_list->rounds->red,
			games_list->rounds->green,
			games_list->rounds->blue
		);
		games_list = games_list->next;
	}

	/* Print sum */
	printf("Sum o'Valid IDs:\n%d\n", sum);

	/* Free the linked list */

	return 0;
}

/* Validate and store a curr_game's stats in a node
 * */
void	parse_game(char *line, t_game **games_list)
{
	t_game	*curr_game;
	t_game	*last_game;
	t_round	*curr_round;
	t_round	*last_round;
	char	*line_cp;
	int		id;
	int		n_cubes;
	int		i;
	int		j;

	/* Init new node */
	curr_game = malloc(sizeof(t_game));
	if (!curr_game)
		return ;
	curr_game->id = 0;
	curr_game->rounds = NULL;
	curr_game->next = NULL;

	/* Loop through the line and parse stats */
	i = -1;
	id = 0;
	while (line[++i])
	{
		// Get each round (round ends at semicolon)
		while (line[i] && (line[i] != ';'))
		{
			// Get ID
			if (isdigit(line[i]) && (id == 0))
			{
				id = atoi(line + i);
				curr_game->id = id;
				++i;
			}
			if (isdigit(line[i]))
			{
				/* Alloc and init round */
				if (!curr_round)
				{
					curr_round = malloc(sizeof(t_round));
					if (!curr_round)
						return ;
					curr_round->red = 0;
					curr_round->green = 0;
					curr_round->blue = 0;
					curr_round->next = NULL;
				}
				j = 0;
				n_cubes = 0;
				// Parse color to set n_cubes to
				while ((line[i + j] != ',') && (line[i + j] != '\0'))
				{
					// Get first n_cubes
					if (isdigit(line[i + j]) && (n_cubes == 0))
						n_cubes = atoi(line + i + j);
					if (isalpha(line[i + j]) && (n_cubes != 0))
					{
						line_cp = line + i + j;
						if (strncmp(line_cp, "red", (long unsigned)3) == 0)
						{
							curr_round->red = n_cubes;
							break ;
						}
						else if (strncmp(line_cp, "green", (long unsigned)5) == 0)
						{
							curr_round->green = n_cubes;
							break ;
						}
						else if (strncmp(line_cp, "blue", (long unsigned)4) == 0)
						{
							curr_round->blue = n_cubes;
							break ;
						}
					}
					++j;
				}
				i += j;
			}
			++i;
		}
		/* Get last round */
		last_round = getlastround(curr_round);
		last_round->next = curr_round;
		curr_round = NULL;
	}

	/* Add node to linked list */
	if (!(*games_list))
	{
		*games_list = curr_game;
		return ;
	}
	last_game = getlastgame(*games_list);
	last_game->next = curr_game;
}

/* Returns pointer to last node in 'games_list' list
 * */
t_game	*getlastgame(t_game *games_list)
{
	while (games_list && games_list->next)
		games_list = games_list->next;
	return (games_list);
}

/* Returns pointer to last round in game 
 * */
t_round	*getlastround(t_round *rounds_list)
{
	while (rounds_list && rounds_list->next)
		rounds_list = rounds_list->next;
	return (rounds_list);
}
