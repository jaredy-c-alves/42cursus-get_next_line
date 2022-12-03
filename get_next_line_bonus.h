/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:57:01 by jcapistr          #+#    #+#             */
/*   Updated: 2022/12/03 10:57:02 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);

char	*ft_strchr(const char *str, int chr);

char	*ft_bufjoin(char *b1, char *b2);

char	*ft_read_fd(int fd, char *buf);

char	*ft_get_line(const char *buf);

char	*ft_move_buf(char *buf);

char	*get_next_line(int fd);

#endif
