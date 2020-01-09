/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int	nb_of_chanks(char *str, char *del)
{
	int	count = 0;

	for (int i = 0 ; str[i] ; i++) {
		if (!strncmp(&str[i], del, strlen(del)))
			count++;
	}
	return (count);
}

int	find_near_position(char *str, int j, int *mode)
{
	for (int i = j ; str[i] ; i++) {
		if (!strncmp(&str[i], "&&", strlen("&&"))) {
			*mode = 1;
			return (i);
		} else if (!strncmp(&str[i], "||", strlen("||"))) {
			*mode = 2;
			return (i);
		}
	}
	return (-1);
}

char	*next_arg(int mode)
{
	if (mode == 1)
		return (strdup("&&"));
	else if (mode == 2)
		return (strdup("||"));
}

char	**get_chunks(char *str)
{
	static int j = 0, k = 0;
	int	mode = 0, c = 0;
	char **argv = malloc(sizeof(*argv) * (((nb_of_chanks(str, "&&") +
		nb_of_chanks(str, "||") + 1) * 2) + 1));
	for (int j = 0 ; j < strlen(str) ; j += 2) {
		if ((j = find_near_position(str, j, &mode)) != -1) {
			argv[c] = test(str, &k, &j);
			argv[++c] = next_arg(mode);
			c++;
		} else {
			argv[c] = strndup(&str[k], strlen(str) - k);
			k = j + 2;
			break;
		}
	}
	argv[++c] = NULL;
	j = 0;	k = 0;
	return (argv);
}

void	status_value(char **av, int i, int *status)
{
	if (!strcmp(av[i], "&&") && *status != 0)
		*status = 1;
	if (!strcmp(av[i], "||") && *status == 0)
		*status = 1;
	else if (!strcmp(av[i], "||") && *status)
		*status = 0;
}
