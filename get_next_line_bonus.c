/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:37:37 by mmiilpal          #+#    #+#             */
/*   Updated: 2024/01/23 17:56:15 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*add_to_buffer(char *buffer, char *char_read)
{
	char	*temp;

	temp = ft_strjoin(buffer, char_read);
	free(buffer);
	return (temp);
}

char	*get_remaining(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer)
		return (free(buffer), NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*read_char(int fd, char *buffer)
{
	char	*char_read;
	ssize_t	bytes;
	size_t	i;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (BUFFER_SIZE < 42 || BUFFER_SIZE > 10000)
		i = 42;
	else
		i = BUFFER_SIZE;
	char_read = ft_calloc(i + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, char_read, i);
		if (bytes == -1)
			return (free(char_read), NULL);
		if (bytes == 0)
			break ;
		char_read[bytes] = 0;
		buffer = add_to_buffer(buffer, char_read);
		if (ft_strchr(char_read, '\n'))
			break ;
	}
	return (free(char_read), buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer[fd] = read_char(fd, buffer[fd]);
	if (*buffer[fd] == 0)
		return (free(buffer[fd]), buffer[fd] = NULL);
	line = get_line(buffer[fd]);
	if (!line)
		return (NULL);
	buffer[fd] = get_remaining(buffer[fd]);
	return (line);
}
