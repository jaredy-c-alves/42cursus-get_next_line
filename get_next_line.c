/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:57:05 by jcapistr          #+#    #+#             */
/*   Updated: 2022/12/03 10:57:05 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_move_buf(char *buf)
{
	char	*new_buf;
	int		i;
	int		j;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	new_buf = (char *)malloc((ft_strlen(buf) - i + 1) * sizeof(char));
	if (new_buf == NULL)
		return (NULL);
	i++;
	j = 0;
	while (buf[i] != '\0')
		new_buf[j++] = buf[i++];
	new_buf[j] = '\0';
	free(buf);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read_fd(fd, buf);
	if (buf == NULL)
		return (NULL);
	line = ft_get_line(buf);
	buf = ft_move_buf(buf);
	return (line);
}
