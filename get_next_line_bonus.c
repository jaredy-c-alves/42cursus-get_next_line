/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:08:41 by jcapistr          #+#    #+#             */
/*   Updated: 2022/12/02 13:12:52 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_fd(int fd, char *buff)
{
	char	*rd_buff;
	ssize_t	rd_bytes;

	rd_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (rd_buff == NULL)
		return (NULL);
	rd_bytes = 1;
	while (ft_strchr(buff, '\n') == NULL && rd_bytes != 0)
	{
		rd_bytes = read(fd, rd_buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(rd_buff);
			return (NULL);
		}
		rd_buff[rd_bytes] = '\0';
		buff = ft_strjoin(buff, rd_buff);
	}
	free(rd_buff);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = ft_read_fd(fd, buff[fd]);
	if (buff[fd] == NULL)
		return (NULL);
	line = ft_get_line(buff[fd]);
	buff[fd] = ft_move_buff(buff[fd]);
	return (line);
}
