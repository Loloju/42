/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:52:01 by odemirel          #+#    #+#             */
/*   Updated: 2022/09/16 11:52:45 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_stack_d	*ft_node_init(int value)
{
	t_stack_d	*head;

	head = malloc(sizeof(t_stack_d));
	if (!head)
	{
		return (0);
	}
	head->data = value;
	head->prev = 0;
	head->next = 0;
	return (head);
}

static void	ft_oneadd(t_stack_d *temp)
{
	temp->next = malloc(sizeof(t_stack_d));
	if (!temp->next)
		return ;
	temp->next->prev = temp;
	temp->next->next = temp;
	temp->prev = temp->next;
}

static void	ft_addbefore(t_stack_d *from, t_stack_d *to)
{
	t_stack_d	*tmp;

	if (!from)
		return ;
	if (!to)
	{
		if (from->next == 0)
			to = from;
		else if (from->next == from->prev)
		{
			from->next = 0;
			from->prev = 0;
		}
	}
}

t_stack_d	*ft_addnode(t_stack_d *head, int value)
{
	t_stack_d	*temp;
	t_stack_d	*t;

	if (!head)
		head = ft_node_init(value);
	else
	{
		temp = head;
		if (temp->prev)
		{
			temp = temp->prev;
		}
		if (temp->next == NULL)
		{
			ft_oneadd(temp);
			temp->next->data = value;
		}
		else
		{
			t = ft_node_init(value);
			t->next = temp->next;
			t->prev = temp;
			temp->next->prev = t;
			temp->next = t;
		}
	}
	return (head);
}
