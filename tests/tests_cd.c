/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

void redirect1_all_std(void);

Test(cd_args, first_test, .init = redirect1_all_std)
{
	char	*args[] = {"cd" , "nn", "nnn", NULL};
	char	*out = strdup("cd: too many arguments.\n");

	cd_args(args);
	cr_assert_stderr_eq_str(out);
}

Test(my_cd, second_test, .init = redirect1_all_std)
{
	char	*args[] = {"cd" , "nn", NULL};
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char *s1 = strdup("najada=najada");
	char *s2 = strdup("najada=najada");
	char	*args1[] = {s, s1, s2, NULL};
	char const *out = "nn: No such file or directory.\n";

	env = create_env_list(args1);
	my_cd(&env, args);
	cr_assert_stderr_eq_str(out);
}

Test(my_cd, third_test, .init = redirect1_all_std)
{
	char	*args[] = {"cd" , "main.c", NULL};
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char *s1 = strdup("najada=najada");
	char *s2 = strdup("najada=najada");
	char	*args1[] = {s, s1, s2, NULL};
	char const *out = "main.c: Not a directory.\n";

	env = create_env_list(args1);
	my_cd(&env, args);
	cr_assert_stderr_eq_str(out);
}
