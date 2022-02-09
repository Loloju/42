/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:43:35 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/09 20:48:19 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_length(int nbr)
{
	if (nbr >= 0 && nbr <= 9)
		return (1);
	else
		return (1 + get_length(nbr / 10));
}

void	write_nbr(char *str, int nbr, int lnt)
{
	if (!(nbr >= 0 && nbr <= 9))
	{
		write_nbr(str, nbr / 10, lnt - 1);
	}
	str[lnt] = (nbr % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		length;
	int		isnegative;

	i = 0;
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
	result = malloc(sizeof(char) * length + 1);
	if (isnegative)
		*result = '-';
	write_nbr (result, n, length - 1);
	result[length + 1] = '\0';
	return (result);
}