/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:37:37 by mmiilpal          #+#    #+#             */
/*   Updated: 2023/12/15 17:42:20 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void	add_to_struct()
{

}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;
	ssize_t			read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}
