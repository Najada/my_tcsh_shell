/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int	dedect_redir(char *str , char redir)
{
	int	count = 0;

	for (int i = 0 ; str[i] ; i++) {
		if (str[i] == redir)
			count++;
	}
	return (count);
}

int	check_redir(char *str, char redir)
{
	for (int i = 0 ; str[i] ; i++) {
		if (str[i] == redir)
			return (i);
	}
	return (-1);
}

char	*redir_out(char **str)
{
	int	index;
	char *out = NULL;
	char *tmp = strdup(*str);

	if ((index = check_redir(tmp, '>')) == -1 ||
		dedect_redir(tmp, '>') != 1)
		return (NULL);
	else {
		int save = index;
		out = my_strdup(&tmp[index] + 1);
		tmp[index] = ' ';
		for (int i = index + 2 ; tmp[i] && tmp[i] != ' '; i++)
			tmp[i] = ' ';
	}
	out = trim(out, ' ');
	out = get_redir_name(out);
	*str = tmp;
	return (out);
}

char	*redir_double_out(char **str)
{
	int	index;
	char *d_out = NULL, *tmp = strdup(*str);

	if ((index = check_redir(tmp, '>')) == -1 ||
		dedect_redir(tmp, '>') != 2) {
		return (NULL);
	} else {
		d_out = my_strdup(&tmp[index + 2]);
		tmp[index] = ' ';
		tmp[index + 1] = ' ';
		while (tmp[index] == ' ')
			index++;
		for (int i = index  ; tmp[i] && tmp[i] != ' ' ; i++)
			tmp[i] = ' ';
	}
	d_out = get_redir_name(trim(d_out, ' '));
	*str = tmp;
	return (d_out);
}

char	*redir_in(char **str)
{
	int	index;
	char *in = NULL;
	char *tmp = strdup(*str);

	if ((index = check_redir(tmp, '<')) == -1 ||
		dedect_redir(tmp, '<') != 1)
		return (NULL);
	else {
		in = my_strdup(&tmp[index + 1]);
		tmp[index] = ' ';
		for (int i = index + 2 ; tmp[i] && tmp[i] != ' ' ; i++)
			tmp[i] = ' ';
	}
	in = get_redir_name(trim(in, ' '));
	*str = tmp;
	return (in);
}
