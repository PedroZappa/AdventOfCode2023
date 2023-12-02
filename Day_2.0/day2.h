#ifndef DAY2_H
# define DAY2_H

# include <ctype.h>			// isdigit() & isalpha()
# include <fcntl.h>			// open() & close()
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

/* Structs to store game data */
typedef struct s_round
{
	int		blue;
	int		red;
	int		green;
	struct t_round	*next;
}		t_round;

typedef struct s_game
{
	int		id;
	struct s_round	*rounds;
	struct s_game	*next;
}		t_game;


#endif
