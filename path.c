/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

char	**get_path_args(env_t **env)
{
	char	*path = my_getenv(*env, "PATH");
	char	**path_args = str_to_array(path, ':');

	return (path_args);
}

void	execute_path(char **my_env, char **args, int status, char **path)
{
	char	*cmd = NULL;

	for (int i = 0 ; path[i] && !status ; i++) {
		cmd = my_mstrcat("/", args[0]);
		cmd = my_mstrcat(path[i], cmd);
		if (access(cmd, X_OK) == 0) {
			if (execve(cmd, args, my_env) == -1) {
				execve_error(args);
			}
		}
		free(cmd);
	}
}

int	ecexute_cmd(env_t **env, char **args)
{
	int	status;
	char	*str = strdup(args[0]);
	char **path = str_to_array(my_getenv(*env, "PATH"), ':');
	char	**my_env = to_string_array(*env);

	status = (execve(args[0], args, my_env) != -1 ? 1 : 0);
	execve_error(args);
	execute_path(my_env, args, status, path);
	if (my_strcmp(args[0], "exit"))
		dprintf(2, "%s: Command not found.\n", str);
	my_free(path);
	my_free(my_env);
	free(str);
	exit(1);
}
