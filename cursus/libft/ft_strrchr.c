/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:33:04 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 21:33:05 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*ptr;

	if (c > 256)
		c -= 256;
	index = -1;
	ptr = 0;
	while (s[++index])
	{
		if (s[index] == c)
			ptr = (char *)(s + index);
	}
	if (s[index] == c)
		ptr = (char *)(s + index);
	return (ptr);
}
