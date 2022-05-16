##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile for bistro
##

SRC	=	main.c	\
		animations/duck_animation.c \
		animations/second_duck_animation.c \
		animations/clock.c 	\
		window.c 	\
		display_background.c	\
		display_text.c	\
		display_gun.c

OBJ	=	$(SRC:.c=.o)

LCSFML 	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio

CFLAGS	=	-Iinclude/ -Llib/my/ -lmy $(LCSFML)

CCRITERION = -coverage -lcriterion

COMPIL	=	gcc

NAME	=	my_hunter

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(COMPIL) -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:
	rm -f unit*
	make -C lib/my/
	gcc -o unit_tests *.c tests/test_hunter.c $(CFLAGS) $(CCRITERION)
	./unit_tests

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C lib/my
	rm -f $(NAME)
	rm -f unit*

re: fclean all

.PHONY : all re clean tests_run fclean
