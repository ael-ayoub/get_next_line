#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int current_line;

	int line = current_line;
	char buffer[1];
	while (read(fd,buffer,1)>0 && line > 0)
	{
		if (buffer[0] == '\n')
		{
			line--;
		}
		continue;
	}
	current_line++;
	printf("%d\n",current_line);

	char *str = (char *)malloc(60);
	read(fd,str,50);
	
	return str;
}
