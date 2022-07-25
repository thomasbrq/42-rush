/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:20:09 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/22 13:31:11 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

/*
	Search a key in the dictionnary then return his value.
	or return NULL.
*/
char	*get_dict_value(t_dict *head, unsigned int n)
{
	t_dict	*first;

	first = head;
	while (first)
	{
		if (n == first->key)
			return (first->value);
		first = first->next;
	}
	return (NULL);
}
