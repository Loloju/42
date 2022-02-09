/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:16:34 by odemirel          #+#    #+#             */
/*   Updated: 2021/12/04 19:06:03 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char str)
{
	if (str >= 'a' && str <= 'z')
	{
		return (1);
	}
	if (str >= 'A' && str <= 'Z')
	{
		return (1);
	}
	if (str >= '0' && str <= '9')
	{
		return (1);
	}
	return (0);
}

char	capitalize(char str)
{
	if (str >= 'a' && str <= 'z')
	{
		str -= 32;
	}
	return (str);
}

char	uncapitalize(char str)
{
	if (str >= 'A' && str <= 'Z')
	{
		str += 32;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alphanumeric (str[i - 1]) == 0)
		{
			str[i] = capitalize(str[i]);
		}
		else
		{
			str[i] = uncapitalize(str[i]);
		}
		i++;
	}
	return (str);
}
