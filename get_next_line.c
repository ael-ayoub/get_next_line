#include "get_next_line.h"


//char	*get_next_line(int fd)
//{
//	if (fd < 0)
//		return (NULL);
	

//	static char str[BUFFER_SIZE + 1];
//	static int index;
//		int bytesread = read(fd,str,BUFFER_SIZE);
//		str[bytesread] = '\0';
	
//		if (BUFFER_SIZE <= 0)
//			return NULL;

		
//	int len_line = lenght_line(str,index);
	
//	char *line;
//	if (index >= bytesread)
//		return NULL;

		
//		line = ft_strdup(str,index,len_line);
	
//	if (!line)
//		return NULL;
//		index += len_line ;


//	return line;
//}

char	*get_next_line(int fd)
{
    static char str[BUFFER_SIZE + 1];
    static int  index;
    char        *line;
    int         bytesread;
    size_t         len_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (str[0] == '\0')
        bytesread = read(fd, str, BUFFER_SIZE);
    if (bytesread <= 0)
        return (NULL);
    str[bytesread] = '\0';
    len_line = lenght_line(str, index);
    if (len_line <= 0)
        return (NULL);
    if (index >= bytesread)
        return (NULL);
    line = ft_strdup(str, index, len_line);
    if (!line)
        return (NULL);
        index += len_line + 1;
    if (len_line == 1)
        index--;
    return (line);
}
