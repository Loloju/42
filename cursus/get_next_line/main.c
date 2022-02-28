#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main( void )
{
	int		x;
	int		b;
	int		i;
	char	*a;
	char	*t;

	b = 1;
	i = 0;
	a = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	t = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	x = open("asd.txt", O_RDONLY, 774);
	while (b != 0)
	{
		b = read(x, a, BUFFER_SIZE);
		t = ft_strjoin(t, a);
	}
	printf("%s\n", t);
}
