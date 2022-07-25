/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary_save.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:50:35 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/25 10:24:15 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

/*
	Take the path of the file, open it then return the file descriptor of
	this file.
*/
int	open_dictionnary_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

/*
	Get the key and the value of each dictionnary entry.
*/
t_dict	*get_dict_values(t_dict *head, char *line)
{
	char	**temp;
	char	*new_value;
	int		line_length;
	int		index;

	index = 1;
	temp = ft_split(line, ' ');
	if (!temp[1])
		return (head);
	if (temp[2])
		index = 2;
	line_length = ft_strlen(temp[index]) + 1;
	new_value = copy_str(line_length, temp[index]);
	head = dict_push(head, copy_key(temp[0]), new_value);
	free_2dchar(temp);
	return (head);
}

/*
	Save each values into the dictionnary stack.
*/
t_dict	*fill_dictionnary(t_dict *head, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line)
		{
			head = get_dict_values(head, line);
			free(line);
		}
		line = get_next_line(fd);
	}
	return (head);
}

/*
	Trim a line to remove space then create new string value with it.
*/
char	*copy_str(int line_length, char *line)
{
	char	*new_str;
	int		i;

	new_str = (char *) malloc(line_length * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	ft_strlcpy(new_str, &line[i], line_length);
	return (new_str);
}

/*
	Transform a string into an unsigned int key.
*/
unsigned int	copy_key(char *key)
{
	unsigned int	ret;

	ret = ft_atoi(key);
	return (ret);
}
