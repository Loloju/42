/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:56:10 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/28 10:09:34 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length(unsigned long nbr)
{
	if (nbr <= 9)
		return (1);
	else
		return (1 + get_length(nbr / 10));
}

static void	write_nbr(char *str, unsigned long nbr, int lnt)
{
	if (!(nbr <= 9))
	{
		write_nbr(str, nbr / 10, lnt - 1);
	}
	str[lnt] = (nbr % 10) + '0';
}

char	*ft_utoa(unsigned int nbr)
{
	unsigned long	n;
	char			*result;
	int				length;

	n = nbr;
	length = 0;
	length = get_length (n);
	result = (char *)malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	write_nbr (result, n, length - 1);
	result[length] = '\0';
	return (result);
}
