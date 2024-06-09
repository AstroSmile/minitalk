/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:38:29 by ana-maro          #+#    #+#             */
/*   Updated: 2024/05/12 22:27:54 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_read_text(int fd, char *stc);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
int		ft_strlen_gnl(char *s);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_find_line(char *stc);
char	*get_next_line(int fd);
char	*ft_free_gnl(char **s);
char	*ft_calloc_gnl(int c);

#endif
