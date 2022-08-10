/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:42:32 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/10 09:55:46 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../so_long.h"
#include <unistd.h>
#include <fcntl.h>

char	*get_line(int fd)
{
	static char	*str;
	char		*buff;
	int			bytes;

	str = malloc(sizeof(char));
	*str = 0;
	bytes = 1;
	buff = malloc(sizeof(char) * 2);
	if (!buff)
		return (0);
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
