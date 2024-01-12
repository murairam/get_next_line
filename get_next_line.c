/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:37:37 by mmiilpal          #+#    #+#             */
/*   Updated: 2024/01/12 18:25:25 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*fill_buffer(int fd, char *buffer)
{
	char	*char_read;
	ssize_t	bytes;

	char_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!char_read)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, char_read, BUFFER_SIZE);
		if (bytes == -1)
			return (free(char_read), NULL);
		buffer = ft_strjoin(buffer, char_read);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(char_read);
	if (bytes == 0 && !ft_strchr(buffer, '\n'))
		return (free(buffer), NULL);
	return (buffer);
} */

char	*read_and_add_to_buffer(int fd, char *buffer)
{
	char	*char_read;
	ssize_t	bytes;

	char_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!char_read)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, char_read, BUFFER_SIZE);
		if (bytes == -1)
			return (free(char_read), NULL);
		buffer = ft_strjoin(buffer, char_read);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(char_read);
	if (bytes == 0 && !ft_strchr(buffer, '\n'))
		return (free(buffer), NULL);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_substr(buffer, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp_buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(buffer, '\n'))
		buffer = read_and_add_to_buffer(fd, buffer);
	if (!buffer)
		return (free(buffer), NULL);
	line = get_line(buffer);
	temp_buf = buffer;
	buffer = ft_substr(buffer, ft_strlen(line) + 1, ft_strlen(buffer));
	free(temp_buf);
	return (line);
}
