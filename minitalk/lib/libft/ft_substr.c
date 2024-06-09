/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:44:11 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/20 22:39:34 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	lens;

	lens = ft_strlen(s);
	if ((size_t)start > lens)
		return (ft_strdup(""));
	if (len > lens - (size_t)start)
		len = lens - (size_t)start;
	new = (char *)malloc(len + 1);
	if (!new)
		return (0);
	ft_strlcpy(new, &s[start], len + 1);
	return (new);
}
