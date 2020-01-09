/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int     my_char_isalpha(char c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
		return (0);
	return (1);
}

int     my_char_is_num(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int     my_str_is_not_alphanum(char a)
{
	if (my_char_isalpha(a) == 0 &&  my_char_is_num(a) == 0)
		return (1);
	return (0);
}

void	setenv_error(void)
{
	my_fputstr(2, "setenv: Variable name");
	my_fputstr(2, " must contain alphanumeric");
	my_fputstr(2, " characters.\n");
}

int	check_setenv(char **args)
{
	int	i = 0;

	if (args[1] == NULL)
		return (1);
	while (args[1][i]) {
		if (my_str_is_not_alphanum(args[1][i]) \
			== 1 && args[1][i] != '_')
			return (0);
		i++;
	}
	return (1);
}
