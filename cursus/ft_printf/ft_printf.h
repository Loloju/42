/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:37:35 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/16 15:51:56 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *count, ...);

int	ft_putchar_len(va_list args, char c);
int	ft_putstr_len(va_list args, char *str);
int	ft_putptr_len(va_list args, unsigned long long ptr);
#endif