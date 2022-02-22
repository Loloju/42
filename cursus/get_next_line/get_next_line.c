/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:45:20 by odemirel          #+#    #+#             */
/*   Updated: 2022/02/22 16:20:03 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			read_bytes;
	static char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
}
