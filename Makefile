##
## EPITECH PROJECT, 2018
## real_navy
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	re all clean fclean