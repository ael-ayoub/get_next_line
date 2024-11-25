#include "get_next_line.h"

size_t	lenght_line(char *str, int index)
{
    size_t	i;

    i = 0;
    if (!str)
        return (0);
    if(str[index] == '\n')
        return 1;
    while (str[index] && str[index] != '\n' && index < BUFFER_SIZE)
    {
        i++;
        index++;
    }
    return (i);
}

char	*ft_strdup(char *src, int index, size_t len)
{
    char	*dest;
    int		i;

    if (!src || len <= 0)
        return (NULL);
    dest = (char *)malloc(len + 1);
    if (!dest)
        return (NULL);
    i = 0;
    if (src[index] == '\n' && len == 1)
    {
        dest[0] = '\n';
        i++;
    }
    while (i < len && src[index] && src[index] != '\n' && index < BUFFER_SIZE)
    {
        dest[i] = src[index];
        index++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
