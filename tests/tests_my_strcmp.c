/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

Test(my_strcmp, my_frist_test)
{
	cr_assert_eq(my_strcmp("a", "b"), -1);
	cr_assert_eq(my_strcmp("b", "a"), 1);
	cr_assert_eq(my_strcmp("b", "b"), 0);
}

Test(my_strdup, first_test)
{
	cr_assert_str_eq(my_strdup("najada"), "najada");
	cr_assert_null(my_strdup(NULL));
}

Test(my_strlen, first_test)
{
	cr_assert_eq(my_strlen("abc"), 3);
	cr_assert_eq(my_strlen(NULL), 0);
}

void redirect1_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_fputstr, first_test, .init = redirect1_all_std)
{
	my_fputstr(1, "najada");
	cr_assert_stdout_eq_str("najada");
}
