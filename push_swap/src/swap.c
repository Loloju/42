/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:15:04 by odemirel          #+#    #+#             */
/*   Updated: 2022/10/24 16:15:05 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	swap(t_list **stack)
{
	t_list	*tmp;
	t_list	*holder;
	int		data;
	int		i;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	tmp = *stack;
	holder = tmp->next;
	data = tmp->content;
	i = tmp->index;
	tmp->content = holder->content;
	tmp->index = holder->index;
	holder->content = data;
	holder->index = i;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{	
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
