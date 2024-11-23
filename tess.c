#include "get_next_line.h"

int main()
{
	char s1[10];
	char s2[10];

	int fd = open ("test.txt",O_RDONLY);
	read(fd,s1,5);
	read(fd,s2,2);
	printf("%s\n",s1);
	printf("%s",s2);
}
