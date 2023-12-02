#include "day2.h"

void	parse_game(char *line, t_game *game);

int main(void)
{
	int		fd;
	int		n_games;
	int		sum;
	char	*line;
	t_game	*games;

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
	games = malloc(sizeof(t_game));
	if (!games)
		return (1);
	games->id = 0;
	games->rounds = NULL;
	games->next = NULL;
	/* Parse the file */
	while ((line = get_next_line(fd)) != NULL)
	{
		/* Parse the game into node's fields */
		parse_game(line, games);
		/* Free the line */
		free(line);
	}
	/* Close the file */
	close(fd);

	/* Parse the linked list into and sum up valid scores  */
	sum = 0;

	/* Print results */
	printf("%d\n", sum);
	/* Free the linked list */

	return 0;
}

/* Validate and store a game's stats in a node */
void	parse_game(char *line, t_game *game)
{
	char	*str_color;
	char	*line_cp;
	int		id;
	int		n_cubes;
	int		i;
	int		j;

	/* Loop through the line and parse stats */
	i = 0;
	id = 0;
	while (line[i])
	{
		// Get ID
		if (isdigit(line[i]) && (id == 0))
			game->id = id;
		// Get 1st round (round ends at semicolon)
		while (line[i] && (line[i] != ';'))
		{
			if (isdigit(line[i]))
			{
				/* Alloc and init round */
				if (!game->rounds)
				{
					game->rounds = malloc(sizeof(t_round));
					if (!game->rounds)
						return ;
					game->rounds->red = 0;
					game->rounds->green = 0;
					game->rounds->blue = 0;
					game->rounds->next = NULL;
				}
				j = 0;
				n_cubes = 0;
				// Get color to set value
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
							game->rounds->red = n_cubes;
						else if (strncmp(line_cp, "green", (long unsigned)5) == 0)
							game->rounds->green = n_cubes;
						else if (strncmp(line_cp, "blue", (long unsigned)4) == 0)
							game->rounds->blue = n_cubes;
					}
					++j;
				}
				i += j;
			}
		++i;
		}
	}
}
