/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:06:21 by odemirel          #+#    #+#             */
/*   Updated: 2022/09/16 10:59:55 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_d	*ft_swap(t_stack_d *head)
{
	head->next->prev = head->prev;
	head->prev = head->next;
	head->next = head->next->next;
	head->prev->next = head;
	head->prev->prev->next = head->prev;
	head = head->prev;
	return (head);
}

t_stack_d	*ft_rotate(t_stack_d *head)
{
	return(head->next);
}

t_stack_d	*ft_rev_rotate(t_stack_d *head)
{
	return(head->prev);
}

void	ft_push(t_stack_d *a, t_stack_d *b)
{
	t_stack_d	*tmp;

	tmp = a;
	
}