/*
** EPITECH PROJECT, 2018
** my_bzero
** File description:
** my_bzero
*/

# include <minishell.h>

void	my_bzero(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size) {
		buffer[i] = 0;
		i++;
	}
}

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') \
		&& (s2[i] != '\0') && i < n)
		i++;
	return (s1[i] - s2[i]);
}

char	*my_strcpy(char *dest, char const *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
