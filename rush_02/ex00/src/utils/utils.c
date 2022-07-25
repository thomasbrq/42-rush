/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:46:38 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/25 10:49:28 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

/*
	Print a string to output.
*/
void	ft_putstr(char *str, int nl)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
	if (nl)
		write(1, "\n", 1);
}

/*
	Free an array of 2 dimensions.
*/
void	free_2dchar(char **array)
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

/*
	Copy an array to another array.
*/
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (src[size])
		size++;
	if (dstsize <= 0)
		return (size);
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}

/*
	Get an array length.
*/
int	ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\n')
	{
		i++;
		j++;
	}
	return (j);
}
