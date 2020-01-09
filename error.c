/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

void	execve_error(char **args)
{
	if (errno == ENOEXEC) {
		my_fputstr(2, args[0]);
		my_fputstr(2, ": Exec format error.");
		my_fputstr(2, " Wrong Architecture.\n");
		exit(0);
	} else if (errno == EACCES) {
		my_fputstr(2, args[0]);
		my_fputstr(2, ": Permission denied.\n");
		exit(0);
	}
}

void	check_signal(int status)
{
	int	signal;

	if (WIFSIGNALED(status)) {
		signal = WTERMSIG(status);
		if (signal == SIGSEGV)
			dprintf(2, "Segmentation fault\n");
		else if (signal == SIGFPE)
			dprintf(2, "Floating exception\n");
	}
}

void	open_error(char *str)
{
	my_fputstr(2, str);
	if (errno == ENOENT)
		my_fputstr(2, ": No such file or directory\n");
	else if (errno == EACCES)
		my_fputstr(2, ": Permission denied\n");
	if (errno == EISDIR)
		my_fputstr(2, ": Is a directory\n");
}
