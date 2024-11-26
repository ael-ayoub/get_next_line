#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDWR, 0777);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
