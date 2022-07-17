/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:22:07 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/16 22:38:54 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

int	is_in_line(t_skyscraper *sky, int i, int k, int width)
{
	int	index;
	int	**map;

	index = 1;
	map = sky->map;
	while (index <= width)
	{
		if (map[i][index] == k)
			return (1);
		index++;
	}
	return (0);
}

int	is_in_col(t_skyscraper *sky, int j, int k, int height)
{
	int	index;
	int	**map;

	index = 1;
	map = sky->map;
	while (index <= height)
	{
		if (map[index][j] == k)
			return (1);
		index++;
	}
	return (0);
}

int	is_valid_solution(int **map, int width, int height)
{
	int	i;
	int	j;

	i = 1;
	while (i <= height)
	{
		j = 1;
		while (j <= width)
		{
			if (map[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	can_place(t_skyscraper *sky, int i, int j, int k)
{
	int	**map;

	map = sky->map;
	if (map[i][j] == 0 && !is_in_line(sky, i, k, sky->width)
						&& !is_in_col(sky, j, k, sky->height))
		return (1);
	return (0);
}
