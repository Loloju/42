/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:36:57 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 20:36:59 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t amount, size_t n)
{
	void	*ptr;

	ptr = malloc (amount * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, amount * n);
	return (ptr);
}
