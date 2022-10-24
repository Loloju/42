/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:56:56 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/28 09:58:47 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(long nbr)
{
	if (nbr >= 0 && nbr <= 9)
		return (1);
	else
		return (1 + get_length(nbr / 10));
}

static void	write_nbr(char *str, long nbr, int lnt)
{
	if (!(nbr >= 0 && nbr <= 9))
	{
		write_nbr(str, nbr / 10, lnt - 1);
	}
	str[lnt] = (nbr % 10) + '0';
}

char	*ft_itoa(int nbr)
{
	long	n;
	char	*result;
	int		length;
	int		isnegative;

	n = nbr;
	length = 0;
	isnegative = 0;
	if (n < 0)
	{
		n *= -1;
		isnegative = 1;
	}
	length = get_length (n);
	if (isnegative)
		length++;
	result = (char *)malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	*result = '-';
	write_nbr (result, n, length - 1);
	result[length] = '\0';
	return (result);
}
