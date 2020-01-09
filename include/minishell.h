/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** minishell1
*/

# ifndef _MINISHELL_H_
# define _MINISHELL_H_

# define RIGHTS	O_CREAT | O_TRUNC | O_WRONLY | O_RDONLY, 0666
# define RIGHT	O_CREAT | O_APPEND | O_WRONLY | O_RDONLY, 0666
# include <built_in.h>
# include <fcntl.h>
# include <unistd.h>
# include <gnl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <utils.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include <errno.h>
# include <signal.h>

typedef struct redir {
	char *in;
	char *out;
	char *d_out;
} redir_t;

void	prompt(void);
char	*my_getenv(env_t *env, char *str);
int  my_pipe(char **, env_t **, bulletin_t **, redir_t);
//redirections
char	*redir_out(char **str);
char	*redir_double_out(char **str);
char	*redir_in(char **str);
# endif // _MINISHELL1_H_
