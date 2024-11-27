/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:49:19 by ael-aiss          #+#    #+#             */
/*   Updated: 2024/11/27 15:11:16 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*copy;
	int		i;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (i <= len)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}

char	*fofo(char **buffer)
{
	char	*line;
	char	*new_buffer;
	char	*new_position;

	new_position = ft_strchr(*buffer, '\n');
	if (new_position)
	{
		line = ft_substr(*buffer, 0, new_position - *buffer + 1);
		new_buffer = ft_strdup(new_position + 1);
		free(*buffer);
		*buffer = new_buffer;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		temp[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		temp[bytes_read] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		buffer = ft_strjoin(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes_read <= 0 && !buffer)
		return (NULL);
	line = fofo(&buffer);
	return (line);
}
