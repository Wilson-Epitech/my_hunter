CC	=	gcc
CFLAGS  = 	-Wextra -Wall -Werror
LDFLAGS = 	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

#SRC	=	$(wildcard *.c)
SRC	=	main.c

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
