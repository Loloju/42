#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int				x;
	char			*a;

	x = open("asd.txt", O_RDONLY, 774);
	while((a = get_next_line(x)))
		printf("\n\t(%s)\n", a);
}
