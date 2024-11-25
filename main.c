#include "get_next_line.h"

int main()
{
	int fd = open("test.txt",O_RDONLY);
	//int fd1 = open("ss.txt",O_RDONLY);



	char *str = get_next_line(fd);
	printf("%s",str);
	//printf("%s",dd);  
}




