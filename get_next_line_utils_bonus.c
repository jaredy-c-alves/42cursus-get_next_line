/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:09:15 by jcapistr          #+#    #+#             */
/*   Updated: 2022/12/02 13:09:18 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *buff, char *rd_buff)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (buff == NULL)
	{
		buff = (char *)malloc(sizeof(char));
		buff[0] = '\0';
	}
	len = ft_strlen(buff) + ft_strlen(rd_buff);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (buff[++i] != '\0')
		str[i] = buff[i];
	j = 0;
	while (rd_buff[j] != '\0')
		str[i++] = rd_buff[j++];
	str[len] = '\0';
	free(buff);
	return (str);
}

char	*ft_get_line(const char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (buff[i] == '\0')
		return (NULL);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_move_buff(char *buff)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	new_buff = (char *)malloc((ft_strlen(buff) - i + 1) * sizeof(char));
	if (new_buff == NULL)
		return (NULL);
	i++;
	j = 0;
	while (buff[i] != '\0')
		new_buff[j++] = buff[i++];
	new_buff[j] = '\0';
	free(buff);
	return (new_buff);
}
