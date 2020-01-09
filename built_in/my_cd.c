/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int	cd_error(char **c, struct stat buf, char **args, char **p)
{
	if (!S_ISDIR(buf.st_mode)) {
		my_fputstr(2, args[1]);
		my_fputstr(2, ": Not a directory.\n");
		return 1;
	} else {
		*p = my_strdup(*c);
		if (chdir(args[1]) == -1) {
				no_acces(args);
				return 1;
		}
		*c = my_strdup(args[1]);
	}
	return (0);
}

int	cd_args(char **args)
{
	if (count_args(args) > 2) {
		my_fputstr(2, "cd: too many arguments.\n");
		return (1);
	}
	return (0);
}

int	cd_no_dir(char **c, struct stat buf, char **args, char **p)
{
	if (stat(args[1], &buf) == - 1){
		my_fputstr(2, args[1]);
		my_fputstr(2, ": No such file or directory.\n");
		return (1);
	} else
		if (cd_error(c, buf, args, p))
			return (1);
	return (0);

}

int	my_cd(env_t **env, char **args)
{
	struct stat buf;
	char 	str1[256], *current = getcwd(str1, 256), *tmp;
	static char *previous = NULL;
	int	status = -1;
	if (cd_args(args))	return 1;
	if (count_args(args) == 1 || my_strcmp(args[1], "~") == 0) {
		const char* home = my_getenv(*env, "HOME");
		previous = my_strdup(current);current = (char*)home;
	} else {
		if (!my_strcmp(args[1], "-")) {
			chdir(previous);tmp = my_strdup(current);
			current = previous;previous = tmp;return 0;
		} else {
			if (cd_no_dir(&current, buf, args, &previous))
				return (1);
		}
	}
	return (0);
}
