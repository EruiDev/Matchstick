##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	src/matchstick.c \
		src/put_functions.c \
		src/errors.c \
		src/sticks.c \
		src/editor.c \
		src/ai.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
