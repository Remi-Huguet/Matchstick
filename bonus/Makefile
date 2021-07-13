##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =           src/matchstick.c		\
		src/init_pictures.c		\
		src/score.c			\
		src/menu.c			\
		src/get_map.c			\
		src/draw.c			\
		src/game.c			\
		src/ai.c			\
		src/stick.c

NAME =		matchstick

CSFMLFLAGS =	-lcsfml-window -lcsfml-graphics -lcsfml-system

all:		$(NAME)

$(NAME):
		gcc	-o	$(NAME)	$(SRC)	$(CSFMLFLAGS) -g

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re:		fclean all

.PHONY: 	re fclean clean all
