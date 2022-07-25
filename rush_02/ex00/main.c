/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:50:54 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/25 10:24:10 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

/*
	Check if the number is under 0.
*/
int	check_number_error(t_dict *dict, int n)
{
	if ((int)n < 0)
	{
		ft_putstr("Error", 1);
		dict_free(dict);
		return (-1);
	}
	return (0);
}

/*
	Check errors or call the right function.
*/
int	checker(t_dict *dict, unsigned int n)
{
	if (check_number_error(dict, n) == -1)
		return (-1);
	if (n >= 0 && n <= 19)
		ft_putstr(get_dict_value(dict, n), 1);
	else
		number_to_letters(dict, n);
	return (0);
}

int	main(int argc, char **argv)
{
	t_dict			*dict;
	int				fd;
	unsigned int	n;

	if (argc > 3 || argc < 2)
		return (-1);
	dict = NULL;
	if (argc == 3)
		fd = open_dictionnary_file(argv[2]);
	else
		fd = open_dictionnary_file("numbers.dict");
	if (fd == -1)
	{
		ft_putstr("Error", 1);
		return (-1);
	}
	dict = fill_dictionnary(dict, fd);
	n = ft_atoi(argv[1]);
	if (checker(dict, n) == -1)
		return (-1);
	dict_free(dict);
	return (0);
}
