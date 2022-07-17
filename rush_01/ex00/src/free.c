/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:24:53 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/16 22:25:18 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

void	free_int2d(t_skyscraper sky, int **map)
{
	int	i;
	int	size;

	i = 0;
	size = sky.height;
	while (i <= (size + 1))
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_char2d(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
