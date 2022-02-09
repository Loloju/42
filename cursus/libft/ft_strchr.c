/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:31:49 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 21:31:50 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (c > 256)
		c -= 256;
	while (s[index])
	{
		if (s[index] == c)
			return ((char *)(s + index));
		index++;
	}
	if (s[index] == c)
		return ((char *)(s + index));
	return (NULL);
}
