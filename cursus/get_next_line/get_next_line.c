/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:45:20 by odemirel          #+#    #+#             */
/*   Updated: 2022/03/02 15:20:14 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int				i;
	char			*a;
	char			*t;
	static char		*buffer;

	i = 0;
	a = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	t = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer)
	{
		printf("\nbuffer : %s\n\n", buffer);
		free(t);
		t = (char *)malloc(sizeof(char)
				*(BUFFER_SIZE + ft_strlen(buffer) + 1));
		t = ft_strjoin(t, buffer);
		ft_bzero(buffer, ft_strlen(buffer));
		free(buffer);
	}
	while (read(fd, a, BUFFER_SIZE) > 0)
	{
		i = 0;
		while (a[i])
		{
			if (a[i] == '\n')
			{
				a[i] = '\0';
				buffer = buff_rest(&a[i + 1]);
				if (!buffer)
					return (NULL);
				t = ft_strjoin(t, a);
				printf("%s",a);
				printf("\\");
				return (t);
			}
			i++;
		}
		t = ft_strjoin(t, a);
		printf("%s\n",a);
	}
	return (NULL);
}
