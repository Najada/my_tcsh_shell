/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup of minishell1
*/

#ifndef _UTILS_H_
#define _UTILS_H_

char	*my_strdup(char *line);
int	my_strcmp(char const *s1, char const *s2);
int	my_strlen(char const *str);
void	my_fputstr(int fd, char const *str);
int	count_args(char  **strings);
char	*get_name(char *str);
int	my_strmcmp(char const *s1, char const *s2);
char	*my_strcat(char *str1, char const *str2);
void	my_bzero(char *buffer, int size);
int	my_strncmp(char const *s1, char const *s2, int n);
char	*my_strcpy(char *dest, char const *src);
void	my_free(char **args);
//my_str_to_word_tab
char	*trim(char *s, char delim);
int	count_word(char *str, char delim);
char	*get_word(char *str, char delim);
char	**str_to_array(char *str, char delim);
char	*my_mstrcat(char *line1 , char *line2);
char    *my_strcat(char *dest , char const * src);
char    **to_string_array(env_t *list);
//error
void	execve_error(char **args);
void	check_signal(int status);
void	open_error(char *str);
#endif // _UTILS_H_
