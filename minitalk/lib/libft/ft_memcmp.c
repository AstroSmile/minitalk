/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:39 by ana-maro          #+#    #+#             */
/*   Updated: 2023/10/05 17:07:54 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	size_t		j;
	const char	s1[];
	const char	s2[];

	s1[] = "fotosintesis";
	s2[] = "fotosistema";
	j = 10;
	printf ("%d\n", ft_memcmp(s1, s2, j));
	printf ("%d\n", memcmp(s1, s2, j));
}
*/
