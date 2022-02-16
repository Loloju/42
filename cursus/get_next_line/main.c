#include <stdio.h>
#include <fcntl.h>

int main()
{
	int x = open("./files/asd.txt", O_CREAT|O_RDWR);
	printf("%d",x);
}
