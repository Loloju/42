/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:52:36 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/28 11:52:53 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	x_get_length(unsigned long long nbr)
{
	if (nbr <= 15)
		return (1);
	else
		return (1 + x_get_length(nbr / 16));
}

static void	write_hex(char *str, unsigned long long nbr, int lnt, char x)
{
	if (!(nbr <= 15))
	{
		write_hex(str, nbr / 16, lnt - 1, x);
	}
	if (x == 'x')
		str[lnt] = HEXA_SMALL[nbr % 16];
	else if (x == 'X')
		str[lnt] = HEXA_BIG[nbr % 16];
}

static char	*ft_xtoa(unsigned long long nbr, char x)
{
	unsigned long long	n;
	char				*result;
	int					length;

	n = nbr;
	length = 0;
	length = x_get_length (n);
	result = (char *)malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	write_hex (result, n, length - 1, x);
	result[length] = '\0';
	return (result);
}

int	ft_putptr_len(unsigned long long arg)
{
	char	*a;
	int		len;

	len = 0;
	len += ft_putstr_len("0x");
	a = ft_xtoa(arg, 'x');
	len += ft_putstr_len(a);
	free (a);
	return (len);
}

int	ft_puthex_len(unsigned int arg, char x)
{
	char	*a;
	int		len;

	len = 0;
	a = ft_xtoa(arg, x);
	len += ft_putstr_len(a);
	free (a);
	return (len);
}
