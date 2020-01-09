/*
** EPITECH PROJECT, 2018
** minisheel
** File description:
** minishemm
*/

# include <minishell.h>

void redirect1_all_std(void);

Test(my_env , second_test, .init = redirect1_all_std)
{
	env_t *env = NULL;
	char *s = strdup("najada=najada");
	char	*args[] = {s, NULL};

	env = create_env_list(args);
	my_env(&env , args);
	cr_assert_stdout_eq_str("najada=najada\n");
}
