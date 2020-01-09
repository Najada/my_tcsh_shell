##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC_DIR	=	$(realpath ..)

SRC	=	$(SRC_DIR)/utils.c	\
		$(SRC_DIR)/utils1.c	\
		$(SRC_DIR)/utils3.c	\
		$(SRC_DIR)/my_bzero.c	\
		$(SRC_DIR)/built_in/env_utils.c	\
		$(SRC_DIR)/built_in/my_setenv.c	\
		$(SRC_DIR)/built_in/my_cd.c	\
		$(SRC_DIR)/built_in/cd_utils.c	\
		$(SRC_DIR)/built_in/my_unsetenv.c	\
		$(SRC_DIR)/built_in/my_env.c	\
		$(SRC_DIR)/built_in/setenv_utils.c	\
		$(SRC_DIR)/str_to_tab.c	\
		$(SRC_DIR)/str_to_tab_utils.c	\
		$(SRC_DIR)/redirection.c	\
		$(SRC_DIR)/my_getenv.c	\
		$(SRC_DIR)/parse/parse_builtins.c	\
		$(SRC_DIR)/parse/parse_cmd.c	\
		$(SRC_DIR)/pipe.c	\
		$(SRC_DIR)/error.c	\
		$(SRC_DIR)/path.c	\
		$(SRC_DIR)/prompt.c	\


SRC_UT_DIR	=	$(realpath .)

SRC_UT	=	$(SRC_UT_DIR)/tests_my_strcmp.c	\
		$(SRC_UT_DIR)/tests_utils2.c	\
		$(SRC_UT_DIR)/tests_str_to_tab.c	\
		$(SRC_UT_DIR)/tests_redirection.c	\
		$(SRC_UT_DIR)/tests_my_bzero.c	\
		$(SRC_UT_DIR)/tests_setenv.c	\
		$(SRC_UT_DIR)/tests_env.c	\
		$(SRC_UT_DIR)/tests_parse.c	\
		$(SRC_UT_DIR)/tests_cd.c	\
		$(SRC_UT_DIR)/tests_path.c	\

OBJ	=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS	=	-Wall -Wextra -I../include --coverage

LDFLAGS	=	-lcriterion -lgcov

NAME	=	units

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm *.gcda  -f $(NAME)
		rm *.gcno  -f $(NAME)
		rm *~ -f $(NAME)
		rm *.o -f $(NAME)

re:		fclean all
