/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:31:22 by odemirel          #+#    #+#             */
/*   Updated: 2022/09/15 14:03:52 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack_d
{
	struct s_stack_d	*prev;
	int					data;
	struct s_stack_d	*next;
}	t_stack_d;

t_stack_d	*ft_addnode(t_stack_d *head, int value);
t_stack_d	*ft_swap(t_stack_d	*head);
t_stack_d	*ft_rotate(t_stack_d *head);
t_stack_d	*ft_rev_rotate(t_stack_d *head);
void		ft_push(t_stack_d *a, t_stack_d *b);
#endif