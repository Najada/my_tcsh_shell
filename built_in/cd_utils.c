/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

void	no_acces(char **args)
{
	if (errno == EACCES) {
		my_fputstr(2, args[1]);
		my_fputstr(2, ": Permission denied.\n");
	}
}
