##
## MY_HUNTER PROJECT, 2022
## My_Hunter
## File description:
## Makefile
##

CC	=	gcc
CFLAGS  = 	-Wextra -Wall -g3
LDFLAGS = 	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC	=	main.c					\
		src/init.c		 		\
		src/close_window.c 		\
		src/mouse_pos.c 		\

#		src/meteor.c	 		\
#		init.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	a.out

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
	$(RM)	$(OBJ)
	$(RM)	*~

fclean	:	clean
	$(RM) -f $(NAME)

re	:	fclean all
