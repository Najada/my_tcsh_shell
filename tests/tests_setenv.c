/*
** EPITECH PROJECT, 2018
** tests
** File description:
** tests
*/

# include <minishell.h>

void redirect1_all_std(void);

Test(my_setenv , first_test)
{
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char *s1 = strdup("najada=najada");
	char *s2 = strdup("najada=najada");
	char	*args[] = {s, s1, s2, NULL};
	char	*args1[] = {"setenv", "najada", "najada", NULL};

	env = create_env_list(args);
	my_setenv(&env, args1);
	for (; env ; env = env->next)
		cr_assert_str_eq(env->key, "najada");
}

Test(my_setenv , third_test)
{
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char *s1 = strdup("najada=najada");
	char *s2 = strdup("najada=najada");
	char	*args[] = {s, s1, s2, NULL};
	char	*args1[] = {"setenv", "najada", "naja", NULL};
	char	*args2[] = {"setenv", "njada", "naja", NULL};

	env = create_env_list(args);
	my_setenv(&env, args1);
	env_t *tmp = env;
	for (; tmp ; tmp = tmp->next)
		cr_assert_str_eq(tmp->key, "najada");
	my_setenv(&env, args2);
	cr_assert_str_eq(env->key, "njada");
}

Test(my_setenv , second_test, .init = redirect1_all_std)
{
	char *p = "setenv: Variable name must contain";
	char	*p2 = " alphanumeric characters.\n";
	char	*output = my_mstrcat(p, p2);
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char *s1 = strdup("najada=najada");
	char *s2 = strdup("najada=najada");
	char	*args[] = {s, s1, s2, NULL};
	char	*args1[] = {"setenv", "l@", "najada", NULL};

	env = create_env_list(args);
	my_setenv(&env, args1);
	cr_assert_stderr_eq_str(output);
}

Test(my_unsetenv , first_test)
{
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char *s1 = strdup("najada=najada");
	char *s2 = strdup("najada=najada");
	char	*args[] = {s, s1, s2, NULL};
	char	*args1[] = {"unsetenv", "najada", NULL, NULL};

	env = create_env_list(args);
	my_unsetenv(&env, args1);
	cr_assert_str_neq(env->key, "najada");
}

Test(my_unsetenv , second_test)
{
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char *s1 = strdup("najada=najada");
	char *s2 = strdup("najada=najada");
	char	*args[] = {s, s1, s2, NULL};
	char	*args1[] = {"unsetenv", "nda", NULL, NULL};

	env = create_env_list(args);
	my_unsetenv(&env, args1);
	for (; env ; env = env->next)
		cr_assert_str_eq(env->key, "najada");
}
