##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CFLAGS =	-W		\
		-Wall		\
		-Wextra

SRC =		src/main.c		\
		src/get_map.c		\
		src/stick.c		\
		src/stick_re.c		\
		src/get_line.c		\
		src/fct.c		\
		src/matchstick.c	\
		src/ai.c		\
		src/my_put.c		\
		src/check_error.c	\
		src/print_error_msg.c	\
		src/print_msg.c

NAME =		matchstick

all:		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) -lncurses -g

clean:
		rm -f $(OBJ)
		make -C tests/ clean

fclean:		clean
		rm -f $(NAME)
		make -C tests/ fclean

re:		fclean all

tests_run:	clean fclean
		make -C tests/ re

.PHONY:		re fclean clean all
