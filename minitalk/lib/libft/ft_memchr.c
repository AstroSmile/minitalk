/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 01:25:59 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/19 01:26:08 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*str;

	i = 0;
	a = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*str == a)
		{
			return (str);
		}
		str++;
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	size_t			b;
	unsigned char	d;
	char			str[] = "hola mundo";

	b = 6;
	d = 'm';
	printf ("%s\n", ft_memchr(str, d, b));
	printf ("%s\n", memchr(str, d, b));
}
*/
