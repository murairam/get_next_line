/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:37:37 by mmiilpal          #+#    #+#             */
/*   Updated: 2024/01/25 18:18:52 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_char(int fd, char *buffer, char *temp)
{
	char	*char_read;
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), NULL);
		else if (bytes == 0)
			break ;
		temp[bytes] = 0;
		if (!buffer)
			buffer = ft_strdup("");
		char_read = buffer;
		buffer = ft_strjoin(char_read, temp);
		free(char_read);
		char_read = NULL;
		if (ft_strchr(temp, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == 0)
		return (0);
	line = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (*line == 0)
		return (free(line), NULL);
	buffer[i + 1] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	temp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!temp)
		return (NULL);
	line = read_char(fd, buffer[fd], temp);
	free(temp);
	temp = NULL;
	if (!line)
		return (NULL);
	buffer[fd] = get_line(line);
	return (line);
}
