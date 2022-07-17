/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:30:02 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/16 22:50:19 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	count_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	find_map_size(int n)
{
	if (n == 16)
		return (4);
	return (0);
}
