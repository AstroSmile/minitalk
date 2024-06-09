/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:28:40 by ana-maro          #+#    #+#             */
/*   Updated: 2024/05/12 22:34:29 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_gnl(char **s)
{
	if (*s)
	{
		free(*s);
		*s = 0;
	}
	return (NULL);
}

char	*ft_new_stc(char *stc)
{
	int		i;
	char	*aux;
	char	*temp;

	if (!stc)
		return (ft_free_gnl(&stc));
	if (ft_strchr_gnl(stc, '\n') == NULL)
		return (ft_free_gnl(&stc));
	else
	{
		aux = ft_strchr_gnl(stc, '\n') + 1;
		i = ft_strlen_gnl(aux);
	}
	temp = ft_calloc_gnl(i + 1);
	if (!temp)
		return (ft_free_gnl(&stc));
	ft_strlcpy_gnl(temp, aux, i + 1);
	ft_free_gnl(&stc);
	stc = temp;
	return (stc);
}

char	*ft_find_line(char *stc)
{
	int		i;
	char	*line;

	if (!*stc)
		return (NULL);
	i = 0;
	while (stc && stc[i] && stc[i] != '\n')
		i++;
	if (stc[i] == '\n')
		line = ft_calloc_gnl(i + 2);
	else
		line = ft_calloc_gnl(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy_gnl(line, stc, i + 2);
	return (line);
}

char	*ft_read_text(int fd, char *stc)
{
	char	*buff;
	int		byte_read;

	buff = ft_calloc_gnl(BUFFER_SIZE + 1);
	if (!buff)
		return (ft_free_gnl(&stc));
	byte_read = 1;
	while (byte_read != 0 && !ft_strchr_gnl(stc, '\n'))
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
		{
			ft_free_gnl(&buff);
			return (ft_free(&stc));
		}
		buff[byte_read] = '\0';
		stc = ft_strjoin_gnl(stc, buff);
		if (!stc)
			return (ft_free_gnl(&buff));
	}
	ft_free_gnl(&buff);
	return (stc);
}

char	*get_next_line(int fd)
{
	static char	*stc[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(stc));
	stc[fd] = ft_read_text(fd, stc[fd]);
	if (!stc[fd])
		return (NULL);
	line = ft_find_line(stc[fd]);
	if (!line || !*line)
		return (ft_free_gnl(&stc[fd]));
	stc[fd] = ft_new_stc(stc[fd]);
	return (line);
}

/*int main(void)
{
	int	fd;

	//char *s;
	fd = open("prueba.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/
