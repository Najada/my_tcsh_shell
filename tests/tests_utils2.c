/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

Test(count_args, first_test)
{
	char *args[] = {"najada", "najada", NULL};

	cr_assert_eq(count_args(args), 2);
}

Test(my_strcat, first_test)
{
	char str[256];

	bzero(str, 256);
	cr_assert_str_eq(my_strcat(str, "najada"), "najada");
}

Test(my_mstrcat, first_test)
{
	cr_assert_str_eq(my_mstrcat("na", "ja"), "naja");
	cr_assert_str_eq(my_mstrcat("na", NULL), "na");
	cr_assert_str_eq(my_mstrcat(NULL, "ja"), "ja");
}

Test(to_string_array, first_test)
{
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char *s1 = strdup("najada=najada");
	char *s2 = strdup("najada=najada");
	char	*args[] = {s, s1, s2, NULL};
	char	**my_env;
	env = create_env_list(args);
	my_env = to_string_array(env);
	for (int i = 0 ; i < 2 ; i++)
		cr_assert_str_eq(my_env[i], "najada=najada");
}

Test(check_promt, first_test)
{
	int	index = 0;

	cr_assert_eq(check_prompt("najada/", &index), 1);
}
