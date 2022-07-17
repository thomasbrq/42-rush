/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:20:35 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/17 12:35:31 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

int	line_satisfied(int **map, int i, int width)
{
	int	index;
	int	temp;
	int	count;

	index = 2;
	temp = map[i][1];
	count = 1;
	while (index <= width)
	{
		if (temp < map[i][index])
		{
			temp = map[i][index];
			count++;
		}
		index++;
	}
	if (count == map[i][0])
		return (1);
	return (0);
}

int	rline_satisfied(int **map, int i, int width)
{
	int	index;
	int	temp;
	int	count;

	index = (width - 1);
	temp = map[i][width];
	count = 1;
	while (index >= 1)
	{
		if (temp < map[i][index])
		{
			temp = map[i][index];
			count++;
		}
		index--;
	}
	if (count == map[i][width + 1])
		return (1);
	return (0);
}

int	rcol_satisfied(int **map, int j, int height)
{
	int	index;
	int	temp;
	int	count;

	index = (height - 1);
	temp = map[height][j];
	count = 1;
	while (index >= 1)
	{
		if (temp < map[index][j])
		{
			temp = map[index][j];
			count++;
		}
		index--;
	}
	if (count == map[height + 1][j])
		return (1);
	return (0);
}

int	col_satisfied(int **map, int j, int height)
{
	int	index;
	int	temp;
	int	count;

	index = 2;
	temp = map[1][j];
	count = 1;
	while (index <= height)
	{
		if (temp < map[index][j])
		{
			temp = map[index][j];
			count++;
		}
		index++;
	}
	if (count == map[0][j])
		return (1);
	return (0);
}
