/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:20:38 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/25 10:54:51 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONNARY_H
# define DICTIONNARY_H
# define BUFFER_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	unsigned int	key;
	char			*value;
	struct s_dict	*next;
}				t_dict;

// Utils
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
unsigned int	ft_atoi(const char *str);
int				ft_strlen(char *str);
char			**ft_split(char const *s, char c);
char			*get_next_line(int fd);
void			free_2dchar(char **array);
void			ft_putstr(char *str, int nl);

// Stack functions
t_dict			*dict_push(t_dict *prev, unsigned int key, char *value);
t_dict			*dict_pop(t_dict *head);
void			dict_free(t_dict *head);

// Dictionnary functions
int				open_dictionnary_file(char *path);
t_dict			*get_dict_values(t_dict *head, char *line);
t_dict			*fill_dictionnary(t_dict *head, int fd);
char			*copy_str(int line_length, char *line);
unsigned int	copy_key(char *key);
char			*get_dict_value(t_dict *head, unsigned int n);

// Algo
int				number_to_letters(t_dict *head, unsigned int n);
char			*get_dict_value(t_dict *head, unsigned int n);

#endif
