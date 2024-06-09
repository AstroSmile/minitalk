/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:09:38 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/15 20:37:38 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				a;
	unsigned char		*d;
	unsigned const char	*s;

	a = 0;
	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (!dst && !src)
		return (0);
	while (a < n)
	{
		(d[a] = s[a]);
		a++;
	}
	return (dst);
}
