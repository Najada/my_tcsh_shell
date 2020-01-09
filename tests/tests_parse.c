/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

Test(init_bulletins, first_test)
{
	bulletin_t	**structs = init_bulletins();
	char	*bulletins[] = {"cd", "env", "setenv", "unsetenv", NULL};

	for (int i = 0 ; structs[i] ; i++)
		cr_assert_str_eq(structs[i]->str, bulletins[i]);
}

Test(parse_bulletins, first_test)
{
	bulletin_t	**structs = init_bulletins();
	bulletin_t	*s;

	s = parse_bulletins("env", structs);
	cr_assert_null(parse_bulletins("najada", structs));
	cr_assert_str_eq(s->str, "env");
}
