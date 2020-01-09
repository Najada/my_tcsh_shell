/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

Test(str_to_tab, first_test)
{
	char *str = strdup("najada	n    ");

	char **args = str_to_array(str, ' ');

	cr_assert_str_eq(args[0], "najada");
	cr_assert_str_eq(args[1], "n");
}

Test(str_to_tab, second_test)
{
	char *str = strdup("	n    ");

	char **args = str_to_array(str, ' ');

	cr_assert_str_eq(args[0], "n");
	cr_assert_null(args[1]);
}
