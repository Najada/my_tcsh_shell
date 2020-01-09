/*
** EPITECH PROJECT, 2018
** utils
** File description:
** minishell1
*/

#include <minishell.h>

int	my_strcmp(char const *s1, char const *s2)
{
	int	i;
	if (!s1)
		return (-1);
	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

char	*my_strdup(char *line)
{
	char	*new_line;
	int	i;

	if (line == NULL || line[0] == '\0')
		return (NULL);
	if ((new_line = malloc(sizeof(*new_line) * \
		(my_strlen(line) + 1))) == NULL)
		return (NULL);
	for (i = 0 ; line[i] ; i++)
		new_line[i] = line[i];
	new_line[i] = '\0';
	return (new_line);
}

int	my_strlen(char const *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

void	my_fputstr(int fd, char const *str)
{
	if (write(fd, str, my_strlen(str)) == -1)
		perror("");
}
