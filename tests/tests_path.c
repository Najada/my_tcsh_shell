/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishel
*/

# include <minishell.h>

Test(get_path_args, first_tets)
{
	env_t *env = NULL;
	char *s = strdup("PATH=najada:najada");
	char *s1 = NULL;
	char	*args[] = {s, NULL};
	char	**arg = NULL;

	env = create_env_list(args);
	arg = get_path_args(&env);
	for (int i = 0 ; arg[i] ; i++)
		cr_assert_str_eq(arg[i], "najada");
}
