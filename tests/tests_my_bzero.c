/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

Test(my_bzero , first_test)
{
	char	str[256];

	bzero(str, 256);
	cr_assert_eq(str[0], 0);
}

Test(my_strncmp, first_test)
{
	cr_assert_eq(my_strncmp("a", "b", 0), -1);
	cr_assert_eq(my_strncmp("b", "a", 0), 1);
	cr_assert_eq(my_strncmp("b", "b", 0), 0);
}

Test(my_strcpy, first_test)
{
	char	str[256];

	bzero(str, 256);
	cr_assert_str_eq(my_strcpy(str, "najada"), "najada");
}

Test(my_getenv, first_test)
{
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char *s1 = strdup("najada=najada");
	char *s2 = strdup("najada=najada");
	char	*args[] = {s, s1, s2, NULL};

	env = create_env_list(args);
	cr_assert_null(my_getenv(env, "PATH"));
	cr_assert_str_eq(my_getenv(env, "najada"), "najada");
}
