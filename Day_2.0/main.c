#include "day2.h"

void	parse_game(char *line, t_game **game);
t_game	*ft_getlastnode(t_game *games);

int main(void)
{
	int		fd;
	int		n_games;
	int		sum;
	char	*line;
	t_game	*games_list;

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
	/* alloc memory & init linked list */
	games_list = malloc(sizeof(t_game));
	if (!games_list)
		return (1);
	games_list->id = 0;
	games_list->rounds = NULL;
	games_list->next = NULL;
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
void	parse_game(char *line, t_game **games)
{
	t_game	*curr_game;
	t_game	*last_game;
	char	*str_color;
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
	i = 0;
	id = 0;
	while (line[i])
	{
		// Get ID
		if (isdigit(line[i]) && (id == 0))
			curr_game->id = id;
		// Get 1st round (round ends at semicolon)
		while (line[i] && (line[i] != ';'))
		{
			if (isdigit(line[i]))
			{
				/* Alloc and init round */
				if (!curr_game->rounds)
				{
					curr_game->rounds = malloc(sizeof(t_round));
					if (!curr_game->rounds)
						return ;
					curr_game->rounds->red = 0;
					curr_game->rounds->green = 0;
					curr_game->rounds->blue = 0;
					curr_game->rounds->next = NULL;
				}
				j = 0;
				n_cubes = 0;
				// Parse color to set n_cubes to
				while ((line[i + j] != ',') && (line[i + j] != ';') && (line[i + j] != '\0'))
				{
					// Get first n_cubes
					if (isdigit(line[i + j]) && (n_cubes == 0))
					{
						str_color = strndup(line + i, 5);
						n_cubes = atoi(str_color);
						free(str_color);
					}
					if (isalpha(line[i + j]))
					{
						n_cubes = 0;
						line_cp = line + i + j;
						if (strncmp(line_cp, "red", (long unsigned)3) == 0)
							curr_game->rounds->red = n_cubes;
						else if (strncmp(line_cp, "green", (long unsigned)5) == 0)
							curr_game->rounds->green = n_cubes;
						else if (strncmp(line_cp, "blue", (long unsigned)4) == 0)
							curr_game->rounds->blue = n_cubes;
					}
					++j;
				}
				i += j;
			}
			++i;
		}
	}

	/* Add node to linked list */
	if (!(*games))
	{
		*games = curr_game;
		return ;
	}
	last_game = ft_getlastnode(*games);
	last_game->next = curr_game;
}

/* Returns pointer to last node in 'games' list
 * */
t_game	*ft_getlastnode(t_game *games)
{
	while (games && games->next)
		games = games->next;
	return (games);
}
