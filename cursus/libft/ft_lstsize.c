/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:29:32 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 21:29:35 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*decoy;
	int		i;

	decoy = lst;
	i = 0;
	while (decoy)
	{
		i++;
		decoy = decoy->next;
	}
	return (i);
}
