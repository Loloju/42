/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:48:02 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/29 12:21:06 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		return (len += ft_putchar_len(va_arg(args, int)));
	if (c == 's')
		return (len += ft_putstr_len(va_arg(args, char *)));
	if (c == 'p')
		return (len += ft_putptr_len(va_arg(args, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (len += ft_itoa_len(va_arg(args, int)));
	if (c == 'u')
		return (len += ft_unsigned_len(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (len += ft_puthex_len(va_arg(args, unsigned int), c));
	if (c == '%')
		return (len += ft_putchar_len('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	valist;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(valist, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			len += ft_putchar_len(str[i]);
		else
		{
			if (str[i + 1] != '\0')
			{
				len += check_flag(str[++i], valist);
			}
			else
				return (-1);
		}
		i++;
	}
	va_end(valist);
	return (len);
}

/* int	main(void)
{
	int	a;
	int	b;
	int	c;

	b = 0;
	a = ft_printf("yelloooo %s %c %d %x %x %x %p %u %u\n",
			"hello there is", 'a', 13, 5555, -5555, INT_MAX, &b, -20, 2374725);
	c = printf("yelloooo %s %c %d %x %x %x %p %u %u\n",
			"hello this is", 'a', 13, 5555, -5555, INT_MAX, &b, -20, 2374725);
	printf("ft: %d pf: %d", a, c);
	return (0);
} */