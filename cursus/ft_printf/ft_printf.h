/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:37:35 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/17 13:51:14 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *count, ...);

int	ft_putchar_len(char arg);
int	ft_putstr_len(char *args);
int	ft_putptr_len(unsigned long long arg);
int	ft_itoa_len(int arg);
int	ft_unsigned_len(unsigned int arg);
int	ft_puthex_len(unsigned int args);
#endif