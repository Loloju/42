/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:42:32 by odemirel          #+#    #+#             */
/*   Updated: 2022/06/21 16:22:06 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

char	*get_line(int fd, int *flag)
{
	char	*str;
	char	*buff;
	int		bytes;

	bytes = 1;
	buff = malloc(sizeof(char) * 2);
	*buff = 0;
	str = malloc(1);
	*str = 0;
	while (bytes && !ft_strchr(buff, '\n'))
	{
		bytes = read(fd, buff, 1);
		str = ft_strjoin(str, buff);
	}
	if (bytes == 0)
		*flag = 1;
	free (buff);
	return (str);
}

int main ()
{
	int fd = open("maps/deneme.ber",O_RDONLY);
	char *str = 0;
	int a;

	a = 0;
	while (a)
	{
		str = get_line(fd, &a);
		printf("%s", str);
	}
	return (0);
}