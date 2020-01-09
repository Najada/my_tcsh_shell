/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

char	**str_to_array(char *str, char delim)
{
	int	i = 0;
	char	*s = trim(str, delim);
	int	nb_words = count_word(s, delim);
	char	**tab = malloc(sizeof(*tab) * (nb_words + 1));

	while (nb_words) {
		tab[i] = get_word(s, delim);
		i++;
		nb_words--;
	}
	tab[i] = NULL;
	free(s);
	return (tab);
}

char	*remove_tabs(char *str)
{
	int	i = 0;

	while (str[i]) {
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (str);
}

char	*trim_semicolon(char *s, char delim)
{
	int	i = 0;
	char	*str = remove_tabs(trim_left(trim_right(s, ' '), ' '));
	char	*new_str = malloc(sizeof(*str) * (my_strlen(str) + 1));

	i = 0;
	my_bzero(new_str, my_strlen(str) + 1);
	while (*str) {
		new_str[i] = *str;
		if (*str == delim ) {
			while (*str == delim )
				str++;
			str--;
		}
		str++;
		i++;
	}
	return (new_str);
}

char	**str_to_array_semicolon(char *str, char delim)
{
	int	i = 0;
	char	*s = trim_semicolon(str, delim);
	int	nb_words = count_word(s, delim);
	char	**tab = malloc(sizeof(*tab) * (nb_words + 1));

	while (nb_words) {
		tab[i] = get_word(s, delim);
		i++;
		nb_words--;
	}
	tab[i] = NULL;
	free(s);
	return (tab);
}
