#ifndef DAY1_H
# define DAY1_H

# include <stdio.h>
# include <fcntl.h>			// open()
// #include "get_next_line.h"
# include "../libft/libft.h"

typedef struct s_calib_val
{
	int		first_dig;
	int		last_dig;
	int		calib_val;
}	t_calib_val;

t_calib_val		get_calib_val(char *line);

#endif
