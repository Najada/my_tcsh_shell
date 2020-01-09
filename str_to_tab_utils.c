/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** minishell2
*/

# include <minishell.h>

char	*trim_right(char *str, char delim)
{
	while ((*str == delim || *str == '\t') && *str)
		str++;
	return (str);
}

char	*trim_left(char *str, char delim)
{
	int	end;

	end = my_strlen(str) - 1;
	while ((str[end] == delim || str[end] == '\t') && end >= 0)
		end--;
	str[end + 1] = '\0';
	return (str);
}

char	*trim(char *s, char delim)
{
	int	i = 0;
	char	*str = trim_left(trim_right(s, ' '), ' ');
	char	*new_str = malloc(sizeof(*str) * (my_strlen(str) + 1));

	my_bzero(new_str, my_strlen(str) + 1);
	while (*str) {
		new_str[i] = *str;
		if (*str == delim || *str == '\t') {
			if (new_str[i] == '\t')
				new_str[i] = ' ';
			while (*str == delim || *str == '\t')
				str++;
			str--;
		}
		str++;
		i++;
	}
	return (new_str);
}

int	count_word(char *str, char delim)
{
	int	count = 1;

	while (*str) {
		if (*str == delim || *str == '\t')
			count++;
		str++;
	}
	return (count);
}

char	*get_word(char *str, char delim)
{
	char	*word = malloc(sizeof(*word) * (my_strlen(str) + 1));
	int	i = 0;
	static int	j = 0;

	my_bzero(word , my_strlen(str) + 1);
	while (str[j] && str[j] != delim && str[j] != '\t') {
		word[i] = str[j];
		j++;
		i++;
	}
	if (str[j] == delim || str[j] == '\t')
		j++;
	if (str[j] == '\0')
		j = 0;
	return (word);
}
