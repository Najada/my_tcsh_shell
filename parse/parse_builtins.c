/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

bulletin_t	*parse_bulletins(char const *str, bulletin_t **structs)
{
	for (int i = 0 ; structs[i] ; i ++) {
		if (my_strcmp(structs[i]->str, str) == 0)
			return (structs[i]);
	}
	return (NULL);
}

bulletin_t	**init_bulletins(void)
{
	char	*bulletins[] = {"cd", "env", "setenv", "unsetenv", NULL};
	void	*f_bulletins[] = {&my_cd, &my_env, &my_setenv, \
				&my_unsetenv, NULL};
	bulletin_t	**structs = malloc(sizeof(*structs) * 5);
	int	i = 0;

	for (i = 0 ; bulletins[i] ; i++) {
		bulletin_t *s = malloc(sizeof(*s));
		s->str = bulletins[i];
		s->f = f_bulletins[i];
		structs[i] = s;
	}
	structs[i] = NULL;
	return (structs);
}

redir_t	get_file_names(char **av)
{
	redir_t	t;
	t.out = redir_out(av);
	t.in = redir_in(av);
	t.d_out = redir_double_out(av);
	return (t);
}

int	parse_cmd(char *s, bulletin_t **structs, env_t **env)
{
	int st = 0;
	s = trim(s, ' ');
	char **av = get_chunks(s);
	for (int i = 0; av[i] ; i++) {
		status_value(av, i, &st);
		if (strncmp(av[i], "||", 2) && strncmp(av[i], "&&", 2) && !st) {
			redir_t r = get_file_names(&av[i]);
			av[i] = trim(av[i] ,' ');
			if (av[i][strlen(av[i]) - 1] == '|')
				dprintf(2, "Invalid null command.\n");
			else {
				char **a = str_to_array(av[i], '|');
				st = my_pipe(a, env, structs, r);
			}
		}
	}
	return (st);
}

char	*test(char *str, int *k, int *j)
{
	char	*s = strndup(&str[*k], *j - *k);

	*k = *j + 2;
	return (s);
}
