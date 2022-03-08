/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:48:02 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/08 15:15:58 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *count, ...)
{
	va_list		valist;
	//int			i;
	char		*a;
	char		*b = (char *)count;

	va_start(valist, count);
	a = va_arg(valist, char *);
	va_end(valist);
	ft_putendl_fd(b,1);
	return (0);
}

int	main( void )
{
	ft_printf("yelloooo");
	return (0);
}
