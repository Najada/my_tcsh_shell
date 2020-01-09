/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

char	*my_getenv(env_t *env, char *str)
{
	env_t	*tmp = env;

	for (; tmp ; tmp = tmp->next) {
		if (!my_strcmp(str, tmp->key))
			return (tmp->data);
	}
	return (NULL);
}
