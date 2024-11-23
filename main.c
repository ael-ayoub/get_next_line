#include "get_next_line.h"

int main()
{
	int fd = open("test.txt",O_RDONLY);

	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	//printf("%s",str);
}
