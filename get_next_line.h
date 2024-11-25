#ifndef GIT_NEXT_LINE
# define GIT_NEXT_LINE

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 33
#endif

size_t	lenght(char *str);
char	*get_next_line(int fd);
size_t	lenght_line(char *str, int index);
char	*ft_strdup(char *src, int index, size_t len);

#endif
