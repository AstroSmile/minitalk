/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:02:21 by ana-maro          #+#    #+#             */
/*   Updated: 2024/05/12 22:30:22 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_calloc_gnl(int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*new;
	int		lent;

	if (!s1)
		s1 = ft_calloc_gnl(1);
	if (!s1 || !s2)
		return (ft_free_gnl+(&s1));
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	lent = len1 + len2 + 1;
	new = (char *)malloc(lent);
	if (!new)
		return (ft_free_gnl(&s1));
	ft_strlcpy_gnl(new, (char *)s1, len1 + 1);
	ft_strlcpy_gnl(&new[len1], s2, lent);
	ft_free_gnl(&s1);
	return ((char *)new);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	j;

	j = 0;
	if (dstsize && src)
	{
		while (src[j] && j < dstsize - 1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	j = 0;
	while (src && src[j])
		j++;
	return (j);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s[i]);
	return (NULL);
}
