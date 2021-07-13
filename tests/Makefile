##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =		ai.c		\
		check_error.c	\
		fct.c		\
		get_map.c	\
		my_put.c	\
		print_msg.c	\
		stick.c		\
		stick_re.c

SRC_TEST =      stick_tests.c

GCOVR_FLAG =    --exclude

TEST_FLAGS =    --coverage -lcriterion

NAME =          unit_tests

all:            $(NAME)

$(NAME):
		mv ../src/*.c ./
		gcc     -o      $(NAME) $(SRC) $(SRC_TEST) $(TEST_FLAGS)
		./$(NAME)
		gcovr $(GCOVR_FLAG) $(SRC_TEST)
		gcovr $(GCOVR_FLAG) $(SRC_TEST) -b
		mv *.c ../src/
		mv ../src/$(SRC_TEST) ./

clean:
		rm -f *.gcno
		rm -f *.gcda

fclean:         clean
		rm -f $(NAME)

re:             fclean all

.PHONY:         re fclean clean all
