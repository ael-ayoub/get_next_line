/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:49:19 by ael-aiss          #+#    #+#             */
/*   Updated: 2024/11/26 19:04:41 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*copy;

	len = 0;
	while (s1[len] != '\0')
		len++;
	// Allocate memory for the new string (+1 for the null terminator)
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL); // Return NULL if malloc fails
	// Copy the contents of the original string into the new string
	for (int i = 0; i <= len; i++)
		copy[i] = s1[i];
	return (copy);
}

// get_next_line reads one line from the file descriptor
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		temp[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	char		*newline_pos;
	char		*new_buffer;

	buffer = NULL;
	line = NULL;
	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes_read = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[bytes_read] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		buffer = ft_strjoin(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes_read <= 0 && !buffer)
		return (NULL);
	newline_pos = ft_strchr(buffer, '\n');
	if (newline_pos)
	{
		line = ft_substr(buffer, 0, newline_pos - buffer + 1);
		new_buffer = ft_strdup(newline_pos + 1);
		free(buffer);
		buffer = new_buffer;
	}
	else
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
	}
	return (line);
}



char *get_next(int fd)
{
	char temp[BUFFER_SIZE + 1];
	char *buffer;
	size_t readb;
	char *line;


	if (!fd || BUFFER_SIZE <= 0)
		return NULL;
	while(readb = read(fd,temp,BUFFER_SIZE)> 0)
	{
		temp[readb] = '\0';
		
		if (!buffer)
		buffer = ft_strdup("");
		buffer = ft_strjoin(buffer,temp);
		if (!buffer)
			return NULL;
		if (ft_strchr(buffer,'\n'))
			break;
	}
	char *new_position = ft_strchr(buffer,'\n');
	char *new_buffer = NULL;
	if (new_position)
	{
		
	}
	else 
	{
		
	}
	return line;
}



