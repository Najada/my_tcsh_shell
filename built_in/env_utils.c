/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int	get_key_length(char *env)
{
	int i = 0;

	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

char	*get_key(char *env)
{
	int	key_length = get_key_length(env);
	char	*key = malloc(sizeof(*key) * (key_length + 1));
	int i;

	for (i = 0 ; env[i] && i < key_length; i++) {
		key[i] = env[i];
	}
	key[i] = 0;
	return (key);
}

env_t	*new_node(char *env)
{
	env_t	*new = malloc(sizeof(*new));

	new->key = get_key(env);
	new->data = my_strdup(&env[my_strlen(new->key)] + 1);
	new->next = NULL;
	return (new);
}

void	add_node(env_t **env, env_t *new)
{
	if (*env == NULL)
		*env = new;
	else {
		new->next = *env;
		*env = new;
	}
}

env_t	*create_env_list(char **envp)
{
	env_t	*env = NULL;

	for (int i = 0 ; envp[i] ; i++) {
		env_t *new = new_node(envp[i]);
		add_node(&env, new);
	}
	return (env);
}
