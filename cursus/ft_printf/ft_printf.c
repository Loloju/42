/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:48:02 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/16 14:01:52 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*birlestir(char *s1, const char *s2, int n)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
	if (!s3)
		return (NULL);
	s3 = ft_strjoin(s3, s1);
	i = ft_strlen(s3);
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

int	check_flag(char c, va_list args, int len)
{
	if (c == 'c')
		return (len += ft_putchar_len(va_arg(args, char), len));
	if (c == 's')
		return (len += ft_putstr_len(va_arg(args, char *), len));
	if (c == 'p')
		return (len += ft_putptr_len(va_arg(args, int), len));
	if (c == 'd' || c == 'i')
		return (len += ft_itoa_len(va_arg(args, int), len));
	if (c == 'u')
		return (len += ft_unsigned_len(va_arg(args, int), len));
	if (c == 'x' || c == 'X')
		return (len += ft_puthex_len(va_arg(args, int), len));
	if (c == '%')
		return (len += ft_putchar_len('%', len));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	valist;
	int		i;
	int		len;
	char	*string;

	i = 0;
	va_start(valist, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		else
		{
			if (str[i + 1] != NULL)
			{
				len += check_flag(str[i++], valist, len);
				i++;
			}
			else
				return (-1);
		}
	}
}

int	main(void)
{
	ft_printf("yelloooo", "asd", "zxc", "askfadsf", "asdf");
	return (0);
}
