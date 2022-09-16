/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:30:42 by odemirel          #+#    #+#             */
/*   Updated: 2022/09/16 09:43:47 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack_d	*stacks[2];
	t_stack_d	*temp;
	int			b;

	(void) ac;
	(void) av;
	stacks[0] = 0;
	stacks[1] = 0;
	for (int i = 0; i <= 5; i++)
	{
		stacks[0] = ft_addnode(stacks[0], i);
		stacks[1] = ft_addnode(stacks[1], (i * 2) + 3);
	}

	b = 0;
	temp = stacks[0];
	while (temp != stacks[0] || b == 0)
	{
		printf("%d %d\n", stacks[0]->data, stacks[1]->data);
		stacks[0] = stacks[0]->next;
		stacks[1] = stacks[1]->next;
		b = 1;
	}
	printf("\n");

	b = 0;
	stacks[0] = ft_swap(stacks[0]);
	stacks[1] = ft_swap(stacks[1]);
	temp = stacks[0];
	while (temp != stacks[0] || b == 0)
	{
		printf("%d %d\n", stacks[0]->data, stacks[1]->data);
		stacks[0] = stacks[0]->next;
		stacks[1] = stacks[1]->next;
		b = 1;
	}
	printf("\n");
	return (0);
}
