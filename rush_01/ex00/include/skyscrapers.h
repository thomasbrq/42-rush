/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:14:19 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/16 22:37:56 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPERS_H
# define SKYSCRAPERS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_skyscraper
{
	int	**map;
	int	width;
	int	height;
}				t_skyscraper;

// check_clue.c
int		line_satisfied(int **map, int i, int width);
int		rline_satisfied(int **map, int i, int width);
int		rcol_satisfied(int **map, int j, int height);
int		col_satisfied(int **map, int j, int height);

// check_valid.c
int		is_in_line(t_skyscraper *sky, int i, int k, int width);
int		is_in_col(t_skyscraper *sky, int j, int k, int height);
int		is_valid_solution(int **map, int width, int height);
int		can_place(t_skyscraper *sky, int i, int j, int k);

// check_free.c
void	free_int2d(t_skyscraper sky, int **map);
void	free_char2d(char **array);

// ft_atoi.c
int		ft_atoi(const char *str);

// ft_split.c
char	**ft_split(char const *s, char c);

// get_map.c
int		**get_map(t_skyscraper *sky, char *argv);

// utils.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		count_array(char **array);
int		find_map_size(int n);

// main.c
void	print_map(int **map, int size);

#endif
