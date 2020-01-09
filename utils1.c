/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int	count_args(char **args)
{
	int	i;

	for (i = 0 ; args[i] ; i++);
	return (i);
}

void	my_free(char **args)
{
	for (int i = 0 ; args[i] ; i++)
		free(args[i]);
	free(args);
}
