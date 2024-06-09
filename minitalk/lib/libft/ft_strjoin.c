/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 02:25:23 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/20 22:38:55 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*new;
	size_t		lent;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	lent = len1 + len2 + 1;
	new = (char *)malloc(lent);
	if (!new)
		return (0);
	ft_strlcpy(new, (char *)s1, len1 + 1);
	ft_strlcpy(&new[len1], s2, lent);
	return ((char *)new);
}
