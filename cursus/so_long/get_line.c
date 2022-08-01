/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:42:32 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/01 16:02:22 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

char	*get_line(int fd)
{
	char	*str;
	char	*buff;
	int		bytes;

	bytes = 1;
	buff = malloc(sizeof(char) * 2);
	*buff = 0;
	str = malloc(2);
	*str = 0;
	while (bytes && !ft_strchr(buff, '\n'))
	{
		bytes = read(fd, buff, 1);
		buff[1] = 0;
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

/* int	main( void )
{
	int		fd;
	char	*str;

	str = "1";
	fd = open("maps/deneme.ber", O_RDONLY);
	while (str)
	{
		str = get_line(fd);
		printf("%s", str);
	}
	return (0);
} */
