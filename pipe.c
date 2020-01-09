/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

int my_pipe(char **args, env_t **env, bulletin_t **structs, redir_t t)
{
	int	nr = count_args(args);
	int	tmpin= dup(0);
	int	tmpout = dup(1);
	bulletin_t *s = NULL;
	int	fdin;
	int	ret;
	int	fdout;
	int	status = 0;

	if (t.in) {
		fdin = open(t.in, O_WRONLY);
	}
	else fdin = dup(tmpin);
	for (int i = 0 ; i < nr ; i++) {
		dup2(fdin, 0);
		close(fdin);
		if (i == nr - 1) {
			if (t.out) {
				fdout = open(t.out, RIGHTS);
			} else if (t.d_out)
				fdout = open(t.d_out, RIGHT);
			else
				fdout = dup(tmpout);
		} else {
			int fdpipe[2];
			if (pipe(fdpipe) < 0)
				return (1);
			fdout = fdpipe[1];
			fdin = fdpipe[0];
		}
		dup2(fdout, 1);
		close(fdout);
		char **argv = str_to_array(args[i], ' ');
		if ((s = parse_bulletins(argv[0], structs))) {
			status = s->f(env, argv);
		}
		else {
			ret = fork();
			if (ret == 0) {
				ecexute_cmd(env, argv);
				exit(1);
			}
		}
	}
	for (int i = 0 ; i < nr ; i++) {
		wait(&status);
		check_signal(status);
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	if (status != 0)
		return (1);
	return (0);
}
