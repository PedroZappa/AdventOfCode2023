#ifndef DAY7_H
# define DAY7_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft/libft.h"

# define SEP		"<====|===|===|===|====>\n"
# define SEPLNG		"<====|===|===|===|===|===|===|===|===|====>\n"
# define CARD_POW	"23456789TJQKA";

enum	HAND_POW {
	NO_COMBO = 0,
	HIGH_CARD = 1,
	TWO_PAIR = 2,
	THREE_OA_KIND = 3,
	FULL_HOUSE = 4,
	FOUR_OA_KIND = 5,
	FIVE_OA_KIND = 6,
};

#endif
