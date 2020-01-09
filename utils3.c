/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

# include <minishell.h>

char    *my_strcat(char *dest , char const * src)
{
	int     i;
	int     j;

	i = my_strlen(dest);
	for (j = 0 ; src[j] != '\0' ; j++)
		dest[i + j] = src[j];
	dest[i+ j] = '\0';
	return (dest);
}

char	*my_mstrcat(char *line1 , char *line2)
{
	int	i = 0;
	int	j = 0;
	char	*line;

	if ((line = malloc(sizeof(*line) * \
		(my_strlen(line1) + my_strlen(line2) + 1))) == NULL)
		return (NULL);
	if (line1) {
	for (i = 0 ; line1[i] != '\0' ; i++)
		line[i] = line1[i];
	}
	if (line2) {
	for (j = 0 ; line2[j] != '\0' ; j++)
		line[i + j] = line2[j];
	}
	line[i + j] = '\0';
	return (line);
}

static int     get_list_size(env_t *list)
{
	int     i = 0;

	for (; list->next ; list = list->next, i++);
	return (i);
}

char    **to_string_array(env_t *list)
{
	char    **ret;
	int     list_size = get_list_size(list);
	int     i = 0;
	env_t   *tmp = list;

	ret = malloc(sizeof(*ret) * (list_size + 1));
	for (; i < list_size ; i++, tmp = tmp->next) {
		ret[i] = malloc(sizeof(tmp->key) *
		(my_strlen(my_mstrcat(tmp->key, tmp->data)) + 1));
		if (tmp->key)
			my_strcpy(ret[i], tmp->key);
		my_strcat(ret[i], "=");
		if (tmp->data)
			my_strcat(ret[i], tmp->data);
	}
	ret[i] = NULL;
	return (ret);
}
