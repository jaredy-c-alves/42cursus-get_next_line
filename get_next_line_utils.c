/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:57:13 by jcapistr          #+#    #+#             */
/*   Updated: 2022/12/03 10:57:15 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	if (str == NULL)
		return (NULL);
	if (chr == '\0')
		return ((char *)(str + ft_strlen(str)));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

char	*ft_bufjoin(char *b1, char *b2)
{
	char	*buf;
	int		i;
	int		j;

	if (b1 == NULL)
	{
		b1 = (char *)malloc(sizeof(char));
		if (b1 == NULL)
			return (NULL);
		b1[0] = '\0';
	}
	buf = (char *)malloc((ft_strlen(b1) + ft_strlen(b2) + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	i = -1;
	while (b1[++i] != '\0')
		buf[i] = b1[i];
	j = 0;
	while (b2[j] != '\0')
		buf[i++] = b2[j++];
	buf[i] = '\0';
	free(b1);
	return (buf);
}

char	*ft_read_fd(int fd, char *buf)
{
	char	*new_buf;
	ssize_t	rd_bytes;

	new_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (new_buf == NULL)
		return (NULL);
	rd_bytes = 42;
	while (ft_strchr(buf, '\n') == NULL && rd_bytes != 0)
	{
		rd_bytes = read(fd, new_buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			free(new_buf);
			return (NULL);
		}
		new_buf[rd_bytes] = '\0';
		buf = ft_bufjoin(buf, new_buf);
	}
	free(new_buf);
	return (buf);
}

char	*ft_get_line(const char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (buf[i] == '\0')
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
