/*
** EPITECH PROJECT, 2018
** minishel
** File description:
** minishell
*/

# ifndef _BUILT_IN_
# define _BUILT_IN_

typedef struct env {
	char	*key;
	char	*data;
	struct env	*next;
} env_t;

typedef struct {
	char *str;
	int	(*f)(env_t **env , char **args);
} bulletin_t;

env_t	*create_env_list(char **env);
int	my_env(env_t **env, char **args);
env_t	*create_env_list(char **envp);
void	add_node(env_t **env, env_t *new);
env_t	*new_node(char *env);
char	*get_key(char *env);
int	get_key_length(char *env);

//my_setenv
int	my_setenv(env_t **env, char **args);
int	check_setenv(char **args);
env_t	*check_key(env_t *env, char *key);
//my_unsetenv
int	my_unsetenv(env_t **env, char **args);
//my_cd
int	my_cd(env_t **env, char **args);
char	**create_args(char *key, char *data);
void	no_acces(char **args);
//parse built_in
int	ecexute_cmd(env_t **env, char **args);
bulletin_t	**init_bulletins(void);
bulletin_t	*parse_bulletins(char const *str, bulletin_t **structs);
int	my_minishell(char **args, env_t **env, bulletin_t **structs);
void	minishell(char **arg, env_t **env, bulletin_t **structs);
void	setenv_error(void);
# endif // _BUILT_IN_
