/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int	my_env(env_t **env, char **args)
{
	env_t *tmp = *env;
	(void)args;

	for (; tmp ; tmp = tmp->next) {
		if (my_strcmp((tmp->key), "")) {
			my_fputstr(1, tmp->key);
			my_fputstr(1, "=");
			my_fputstr(1, tmp->data);
			my_fputstr(1, "\n");
		}
	}
}
