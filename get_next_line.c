/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:49:19 by ael-aiss          #+#    #+#             */
/*   Updated: 2024/11/26 10:49:20 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	static int	index;
	char		*line;
	int			bytesread;
	size_t		len_line;

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
	index += len_line + 1;
	if (len_line == 1)
		index--;
	return (line);
}
