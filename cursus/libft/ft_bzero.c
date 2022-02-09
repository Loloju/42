/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:36:22 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 20:36:46 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *source, size_t n)
{
	char	*ptr;
	size_t	index;

	if (n == 0)
		return ;
	ptr = source;
	index = 0;
	while (index < n)
		*(ptr + index++) = 0;
}
