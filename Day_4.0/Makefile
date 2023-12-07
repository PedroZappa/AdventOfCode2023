NAME		= libft.a

LIBFT_PATH	= ../libft

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
INCS	= -I .

all : $(NAME)

$(NAME) :
	make -C $(LIBFT_PATH) extra
	cp $(LIBFT_PATH)/libft.a $(NAME)
	$(CC) $(CFLAGS) $(INCS) main.c $(NAME) -o a.out

clean :
	$(RM)
	make -C $(LIBFT_PATH) clean

fclean : clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
