/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:55:43 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/16 18:55:50 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

int	ft_atoi(const char *str)
{
	int		ret;
	int		minus;
	char	*str2;

	minus = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' && minus++ == 0)
		str++;
	else if (*str == '+')
		str++;
	ret = 0;
	str2 = (char *)str;
	while (*str2 >= '0' && *str2 <= '9')
		str2++;
	if ((str2 - str) > 10 && minus == 0)
		return (-1);
	else if ((str2 - str) > 10 && minus == 1)
		return (0);
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + *str++ - '0';
	if (minus)
		ret *= -1;
	return (ret);
}
