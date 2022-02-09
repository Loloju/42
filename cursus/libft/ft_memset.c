/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:30:38 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 21:30:38 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;
	size_t	index;

	ptr = (char *)str;
	index = 0;
	while (index < n)
	{
		ptr[index] = c;
		index++;
	}
	return (ptr);
}
