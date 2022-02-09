/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:28:28 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 21:28:28 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*decoy;
	t_list	*t;

	decoy = *lst;
	while (decoy)
	{
		(*del)(decoy->content);
		t = decoy->next;
		free(decoy);
		decoy = t;
	}
	*lst = NULL;
}
