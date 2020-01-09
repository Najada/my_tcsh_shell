/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int	check_prompt(char *str, int *index)
{
	int	count = 0;

	for (int i = 0 ; str[i] ; i++) {
		if (str[i] == '/') {
			count++;
			*index = i;
		}
	}
	return (count);
}

char    *costumize_prompt(void)
{
	char    str1[256];
	char    *pwd = malloc(sizeof(*pwd) * 256);
	char    *current = getcwd(str1, 256);
	int     index = 0;

	my_bzero(pwd, 256);
	if (check_prompt(current, &index) == 3 &&
		my_strncmp(current, "~/home", 5))
		my_strcat(pwd, "~/");
	else if (check_prompt(current, &index) == 2 &&
		my_strncmp(current, "~/home", 5)) {
		my_strcat(pwd, "~");
		return (pwd);
	}
	my_strcat(pwd, &current[index + 1]);
	return (pwd);
}

void	prompt(void)
{
	char	*str = costumize_prompt();

	if (isatty(0)) {
		my_fputstr(1, "\033[34m[najada@localhost ");
		my_fputstr(1, "\033[31m");
		my_fputstr(1, str);
		my_fputstr(1, "\033[0m");
		my_fputstr(1, "\033[34m ]\033[0m");
		my_fputstr(1, "\033[0m\033[31m~>\033[0m");
		my_fputstr(1, " $ ");
	}
	free(str);
}
