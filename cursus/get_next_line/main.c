#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int x = open("asd.txt", O_RDWR| O_APPEND | O_CREAT, S_IRWXU | S_IRWXG | S_IROTH);
	//int i = 0;
	char *a;
	/*while (i < 10)
	{
		write(x, "merhaba", 7);
		if(i < 9)
			write(x, "\n", 1);
		i++;
	}*/

	a = (char *)malloc(sizeof(char) * 20);

	close(x);

	x = open("asd.txt", O_RDONLY, S_IRWXU | S_IRWXG | S_IROTH);
	int b = read(x, a, 7);

	printf("\n\033[1;32m%d, %d, %s\033[0m\n", b, x, a);
	write(1, a, b);
}
