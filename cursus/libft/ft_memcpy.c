/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:30:22 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 21:30:23 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char			*dest;
	const char		*src;

	if (!destination && !source)
		return (NULL);
	if (destination == source || n == 0)
		return (destination);
	dest = (char *) destination;
	src = (const char *) source;
	while (n--)
		dest[n] = src[n];
	return (dest);
}
