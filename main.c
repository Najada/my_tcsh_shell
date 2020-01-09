/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

void	free_built_in(bulletin_t **structs, env_t *env)
{
	for (int i = 0 ; structs[i] ; i++)
		free(structs[i]);
	for (; env ; env = env->next) {
		free(env->key);
		free(env->data);
		free(env);
	}
	free(structs);
}

void	handle_sigint(int t)
{
	(void)t;
	my_fputstr(1, "\n");
	prompt();
}

int	main(int argc, char **argv, char **envp)
{
	char	*s = NULL;
	env_t	*env = create_env_list(envp);
	bulletin_t	**structs = init_bulletins();

	signal(SIGINT, handle_sigint);
	while (!s || my_strcmp(s, "exit")) {
		prompt();
		free(s);
		if (!(s = get_next_line(0)))
			exit(0);
		char	**args  = str_to_array_semicolon(s, ';');
		for (int i = 0 ; args[i] ; i++)
			parse_cmd(args[i], structs, &env);
		my_free(args);
	}
	free(s);
	free_built_in(structs, env);
	return (0);
}
