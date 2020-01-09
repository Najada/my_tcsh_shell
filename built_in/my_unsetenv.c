/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int	my_unsetenv(env_t **env, char **args)
{
	env_t	*tmp = *env;

	for (; tmp ; tmp = tmp->next) {
		if (!my_strcmp(tmp->key, args[1])) {
			tmp->key = "";
			tmp->data = "";
		}
	}
}
