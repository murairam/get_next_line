/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:37:37 by mmiilpal          #+#    #+#             */
/*   Updated: 2024/01/09 19:21:46 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

/* char	*new_line(char *line_buffer)
{
	char	*lines_read;

	return (lines_read);
}

char	*fill_buffer(int fd, char *lines_read, char *buffer)
{
	char	*line;

	if (!line)
		return (NULL);
	while (bytes > 0)
	{
		if (bytes > 0)
		{
			if (ft_strchr(line[bytes], '\n)') != 0)
				break ;
		}
	}
	return (lines_read);
} */

char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (free(buffer), NULL);
	return (buffer);
}
