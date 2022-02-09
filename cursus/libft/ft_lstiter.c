/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:28:43 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 21:28:44 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*decoy;

	decoy = lst;
	if (lst)
	{
		while (decoy)
		{
			f(decoy->content);
			decoy = decoy->next;
		}
	}
}
