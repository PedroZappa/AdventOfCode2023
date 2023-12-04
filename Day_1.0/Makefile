NAME		= libday1.a

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRC = main.c

OBJS = $(SRC:.c=.o)

MAKE		= make -C
CFLAGS		= -Wall -Wextra -Werror -g
INC			= -I .
CC			= cc
RM			= rm -f
AR			= ar rcs

all: $(NAME)

.o:.c
	@echo "\nCompiling $<"
	$(CC) $(CFLAGS) $(INC) -c $<

$(NAME): $(OBJS)
	@echo "\nCompiling libft..."
	$(MAKE) ../$(LIBFT_PATH) extra
	cp $(LIBFT) Day_1.0/$(NAME)
	@echo "\nBuilding archive..."
	$(AR) $(NAME) $(OBJS)
	@echo "\n\tSUCCESS!"

clean: 
	$(MAKE) ../$(LIBFT_PATH) clean
	Day_1.0/$(RM) $(OBJS)

fclean: clean
	$(MAKE) ../$(LIBFT_PATH) fclean
	Day_1.0/$(RM) $(NAME)

re: fclean all	

.PHONY: all clean fclean re
