##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	main.c			\
		my_putchar.c		\
		my_putstr.c		\
		my_getnbr.c		\
		my_atoi.c		\
		my_put_nbr.c		\
		map_management.c	\
		game_management.c	\
		matches.c		\
		line.c			\
		error.c			\
		my_strlen.c		\

OBJ	=	$(SRC:.c=.o)


NAME    =       matchstick

all:    $(NAME)

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(SRC)	-g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
