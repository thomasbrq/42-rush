/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:38:44 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/25 11:01:20 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

/*
	Count the number digits.
*/
int	count_digits(long long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

/*
	Transform a number with 2 digits in letters.
*/
void	two_digits(unsigned int n, t_dict	*head, t_dict	*node)
{
	int		first;
	int		remainder;
	char	*value;

	first = (n / 10) * 10;
	remainder = (n % 10);
	value = get_dict_value(head, n);
	if (value)
		ft_putstr(value, 0);
	else
	{
		if (first > 0)
			ft_putstr(get_dict_value(head, first), 0);
		if (remainder > 0)
			ft_putstr(get_dict_value(head, remainder), 0);
	}
	if (node->key > 99)
		ft_putstr(node->value, 0);
}

/*
	Transform a number with 3 digits in letters.
*/
void	three_digits(unsigned int n, t_dict	*head, t_dict	*node)
{
	int	first;
	int	remainder;

	first = (n / 100);
	remainder = (n % 100);
	ft_putstr(get_dict_value(head, first), 0);
	ft_putstr("hundred", 0);
	two_digits(remainder, head, node);
}

static void	check_ndigits(t_dict *head, t_dict *temp, int first)
{
	if (count_digits(first) == 1 && first > 0)
	{
		ft_putstr(get_dict_value(head, first), 0);
		ft_putstr(temp->value, 0);
	}
	else if (count_digits(first) == 2)
		two_digits(first, head, temp);
	else if (count_digits(first) == 3)
		three_digits(first, head, temp);
}

/*
	The algorithm to transform an unsigned int number to letters.
	42 => forty two.
*/
int	number_to_letters(t_dict *head, unsigned int n)
{
	t_dict			*temp;
	int				first;
	unsigned int	remainder;

	temp = head;
	first = n;
	remainder = n;
	while (temp && temp->key > 99)
	{
		first = (remainder / temp->key);
		remainder = (remainder % temp->key);
		check_ndigits(head, temp, first);
		temp = temp->next;
	}
	if (remainder > 0 && count_digits(remainder) > 1)
		two_digits(remainder, head, temp);
	else if (remainder > 0)
		ft_putstr(get_dict_value(head, remainder), 0);
	write(1, "\n", 1);
	return (0);
}
