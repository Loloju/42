/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:29:21 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 21:29:22 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*decoy;

	decoy = (t_list *)malloc(sizeof(t_list));
	if (!decoy)
		return (NULL);
	decoy->content = content;
	decoy->next = NULL;
	return (decoy);
}
