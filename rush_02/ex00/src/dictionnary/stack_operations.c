/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:31:06 by tbraquem          #+#    #+#             */
/*   Updated: 2022/07/25 10:53:18 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

/*
	Free the stack.
*/
void	dict_free(t_dict *head)
{
	while (head)
		head = dict_pop(head);
}

/*
	Create a new node in the dictionnary.
*/
t_dict	*dict_push(t_dict *previous, unsigned int key, char *value)
{
	t_dict	*new_node;

	new_node = NULL;
	new_node = (t_dict *) malloc(sizeof(t_dict));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	if (!previous)
		new_node->next = NULL;
	else
		new_node->next = previous;
	return (new_node);
}

/*
	Remove the head node of the stack.
*/
t_dict	*dict_pop(t_dict *head)
{
	t_dict	*next;

	if (!head)
		return (NULL);
	next = head->next;
	free(head->value);
	free(head);
	if (!next)
		head = NULL;
	else
		head = next;
	return (head);
}
