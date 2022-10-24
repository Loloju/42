/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:45:34 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/28 11:40:43 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char args)
{
	write(1, &args, 1);
	return (1);
}

int	ft_putstr_len(char *args)
{
	int	len;

	len = 0;
	if (args == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (args[len])
	{
		ft_putchar_len(args[len]);
		len++;
	}
	return (len);
}

int	ft_unsigned_len(unsigned int arg)
{
	int		len;
	char	*a;

	len = 0;
	a = ft_utoa(arg);
	len = ft_putstr_len(a);
	free(a);
	return (len);
}

int	ft_itoa_len(int arg)
{
	int		len;
	char	*a;

	a = ft_itoa(arg);
	len = ft_putstr_len(a);
	free(a);
	return (len);
}
