/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:57:52 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/16 22:27:20 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

int	**malloc_array(int size)
{
	int	**array;
	int	i;

	array = (int **) malloc((size + 2) * sizeof(int *));
	if (!array)
		return (NULL);
	i = 0;
	while (i <= (size + 1))
	{
		array[i] = (int *) malloc((size + 2) * sizeof(int));
		if (array[i] == NULL)
			return (NULL);
		i++;
	}
	return (array);
}

void	fill_column(t_skyscraper *sky, char **temp, int index)
{
	int	i;
	int	size;
	int	**map;

	i = 1;
	size = sky->width;
	map = sky->map;
	while (i < (size + 1))
	{
		map[i][0] = ft_atoi(temp[index]);
		map[i][size + 1] = ft_atoi(temp[index + size]);
		index++;
		i++;
	}
}

int	**fill_map(t_skyscraper *sky, int **map, int size, char **temp)
{
	int	i;
	int	y;
	int	x;
	int	character;

	i = 0;
	y = 0;
	while (y <= (size + 1))
	{
		x = 0;
		while (x <= (size + 1))
		{
			character = 0;
			if ((y == 0 || y == (size + 1)) && (x == 0 || x == (size + 1)))
				character = -1;
			else if ((y == 0 || y == (size + 1)) && (x > 0 || x < (size + 1)))
				character = ft_atoi(temp[i++]);
			map[y][x] = character;
			x++;
		}
		y++;
	}
	fill_column(sky, temp, i);
	return (map);
}

int	**get_map(t_skyscraper *sky, char *argv)
{
	char	**temp;
	int		array_length;
	int		size;

	temp = ft_split(argv, ' ');
	array_length = count_array(temp);
	size = find_map_size(array_length);
	if (size <= 0)
	{
		free_char2d(temp);
		return (NULL);
	}
	sky->width = size;
	sky->height = size;
	sky->map = malloc_array(size);
	if (sky->map == NULL)
	{
		free_char2d(temp);
		return (NULL);
	}
	sky->map = fill_map(sky, sky->map, size, temp);
	free_char2d(temp);
	return (sky->map);
}
