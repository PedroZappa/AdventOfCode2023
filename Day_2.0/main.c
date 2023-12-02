#include <stdio.h>
#include <fcntl.h>			// open()
#include <string.h>			// strstr()
#include "get_next_line.h"

typedef struct s_round
{
	int		blue;
	int		red;
	int		green;
	t_round	*next;
}		t_round;

typedef struct s_game
{
	int		id;
	t_round	*rounds;
}		t_game;


int main(void)
{
	int		fd;
	int		n_games;
	char	*line;

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
		/* Parse the line */
	}
	/* Close the file */
	close(fd);
	/* Print results */

	return 0;
}
