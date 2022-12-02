/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:08:32 by jcapistr          #+#    #+#             */
/*   Updated: 2022/12/02 13:09:02 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif //BUFFER_SIZE

int		ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char *buff, char *rd_buff);

char	*ft_get_line(const char *buff);

char	*ft_move_buff(char *buff);

char	*get_next_line(int fd);

#endif //GET_NEXT_LINE_BONUS_H
