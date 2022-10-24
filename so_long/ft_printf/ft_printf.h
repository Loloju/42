/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:37:35 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/28 10:45:39 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define HEXA_BIG "0123456789ABCDEF"
# define HEXA_SMALL "0123456789abcdef"

int		ft_printf(const char *count, ...);
int		ft_putchar_len(char arg);
int		ft_putstr_len(char *args);
int		ft_putptr_len(unsigned long long arg);
int		ft_itoa_len(int arg);
int		ft_unsigned_len(unsigned int arg);
int		ft_puthex_len(unsigned int args, char x);
char	*ft_utoa(unsigned int nbr);
#endif