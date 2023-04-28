##
## EPITECH PROJECT, 2023
## IA INTRODUCTORY PROJECT
## File description:
## Makefile
##


_SRC =			main.c \
				stop.c\
				split_str.c\
				update_speed.c\
				update_angle.c\
				turn.c\
				forward.c\
				tools.c\
				displayer.c\

SRCDIR = 		src/

SRC =			$(addprefix $(SRCDIR), $(_SRC))
OBJ = 			$(SRC:.c=.o)

INC = 			-I./include -I.

CFLAGS 	=		-W -Wall -Wextra -Werror -g

NAME = 			ai

all: 			$(NAME) clean

$(NAME):
				@gcc -o $(NAME) $(SRC) $(INC) $(CFLAGS)
				@$(MAKE) clean -s

clean:
				@rm -f $(OBJ)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all

color = /bin/echo -e "\x1b[33m $1\x1b[0m"

run: re
	clear
	@$(call color,"🚀:")
	@./$(NAME) $(ARGS)
