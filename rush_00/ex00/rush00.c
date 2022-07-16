/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:19:23 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/16 15:18:21 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char space, char border)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == (x - 1))
			ft_putchar(border);
		else
			ft_putchar(space);
		i++;
	}
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0 || i == (y - 1))
			print_line(x, '-', 'o');
		else
			print_line(x, ' ', '|');
		ft_putchar('\n');
		i++;
	}
}
