/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:14:49 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/17 12:59:38 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

void	print_map(int **map, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i <= size)
	{
		j = 1;
		while (j <= size)
		{
			ft_putchar(map[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	is_solved(t_skyscraper *sky, int position)
{
	int	i;
	int	j;
	int	k;

	if (position == (sky->width * sky->height))
		return (1);
	i = (position / sky->height) + 1;
	j = (position % sky->width) + 1;
	k = 1;
	while (k <= sky->width)
	{
		if (can_place(sky, i, j, k))
		{
			sky->map[i][j] = k;
			if (is_solved(sky, position + 1)
				&& line_satisfied(sky->map, i, sky->width)
				&& rline_satisfied(sky->map, i, sky->width)
				&& col_satisfied(sky->map, j, sky->height)
				&& rcol_satisfied(sky->map, j, sky->height))
				return (1);
		}
		sky->map[i][j] = 0;
		k++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_skyscraper	sky;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	sky.map = get_map(&sky, argv[1]);
	if (sky.map == NULL)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	is_solved(&sky, 0);
	if (!is_valid_solution(sky.map, sky.width, sky.height))
	{
		free_int2d(sky, sky.map);
		ft_putstr("Error\n");
		return (-1);
	}
	print_map(sky.map, sky.width);
	free_int2d(sky, sky.map);
	return (0);
}
