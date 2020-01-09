/*
** EPITECH PROJECT, 2018
** shell
** File description:
** shell
*/

# include <minishell.h>

char	*get_redir_name(char *str)
{
	for (int i = 0 ; str[i] ; i++) {
		if (str[i] == ' ' && str[i - 1] != '\\')
			str[i] = '\0';
	}
	return (str);
}
