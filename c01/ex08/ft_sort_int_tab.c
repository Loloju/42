/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:14:58 by odemirel          #+#    #+#             */
/*   Updated: 2021/12/07 12:14:50 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	cup;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				cup = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = cup;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
