##
## EPITECH PROJECT, 2018
## 42sh
## File description:
## 42sh
##

SRC	=	str_to_tab.c	\
		str_to_tab_utils.c	\
		main.c	\
		built_in/my_env.c	\
		built_in/env_utils.c	\
		built_in/my_cd.c	\
		built_in/cd_utils.c	\
		built_in/my_setenv.c	\
		built_in/my_unsetenv.c	\
		utils.c	\
		prompt.c	\
		parse/parse_builtins.c	\
		parse/parse_cmd.c	\
		utils1.c	\
		utils3.c	\
		my_getenv.c	\
		path.c	\
		my_bzero.c	\
		pipe.c	\
		redirection.c	\
		error.c	\
		built_in/setenv_utils.c	\
		redir_utils.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	=	-I./include -W -Wall -Wextra -L./lib/my -ggdb -g3

LDFLAGS =	-lgnl


all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm *~ -f $(NAME)
		rm *.gcda  -f $(NAME)
		rm *.gcno  -f $(NAME)
		rm *~ -f $(NAME)
		rm *.o -f $(NAME)

re:		fclean all

tests_run:
		make -C ./tests/
		./tests/units
