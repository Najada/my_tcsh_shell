/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** minishell2
*/

# include <minishell.h>

env_t	*check_key(env_t *env, char *key)
{
	env_t	*tmp = env;

	for (; tmp ; tmp = tmp->next) {
		if (!my_strcmp(key, tmp->key))
			return (tmp);
	}
	return (NULL);
}

int	my_setenv(env_t **env, char **args)
{
	env_t	*new;


	if (count_args(args) == 1) {
		my_env(env, args);
		return;
	} else if (check_setenv(args) == 0) {
		setenv_error();
		return;
	}
	if (!(new = check_key(*env, args[1]))) {
		new = malloc(sizeof(*new));
		new->key = my_strdup(args[1]);
		new->data = my_strdup(args[2]);
		new->next = NULL;
		new->next = *env;
		*env = new;
	} else
		new->data = my_strdup(args[2]);
}
