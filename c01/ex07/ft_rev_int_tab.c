/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:14:58 by odemirel          #+#    #+#             */
/*   Updated: 2021/12/01 15:39:32 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	cup;

	i = 0;
	j = 0;
	while (i < size / 2)
	{
		cup = tab[i];
		tab[i] = tab[(size - 1) - i];
		tab[(size - 1) - i] = cup;
		i++;
	}
}
