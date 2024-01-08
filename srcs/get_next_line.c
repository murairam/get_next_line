/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:37:37 by mmiilpal          #+#    #+#             */
/*   Updated: 2024/01/08 19:51:37 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*new_line(char *line_buffer)
{
	char	*lines_read;

	return (lines_read);
}

char	*fill_buffer(int fd, char *lines_read, char *buffer)
{
	char	*line;
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			if (ft_strchr(line[bytes], '\n)') != 0)
				break ;
		}
	}
	return (lines_read);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = fill_buffer(fd, next)
}
