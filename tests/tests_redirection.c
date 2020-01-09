/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

Test(redir_out, first_test)
{
	char	*s = strdup("cat > data");

	cr_assert_str_eq(redir_out(&s), "data");
	cr_assert_null(redir_out("najada"));
}

Test(redir_double_out, first_test)
{
	char	*s = strdup("cat >> data");

	cr_assert_str_eq(redir_double_out(&s), "data");
	cr_assert_null(redir_double_out("najada"));
}

Test(redir_in, first_test)
{
	char	*s = strdup("cat < data");

	cr_assert_str_eq(redir_in(&s), "data");
	cr_assert_null(redir_in("najada"));
}
