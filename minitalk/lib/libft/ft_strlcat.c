/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:53:48 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/19 21:17:41 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	i = lend;
	j = 0;
	if (dstsize <= lend)
		return (lens + dstsize);
	while ((dstsize - 1) > i && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lend + lens);
}

/*int	main()
{
	char		a[] = "hola";
	const char	b[] = "mundo";
	const char	c1[] = "mundo";

	printf ("%zu\n", ft_strlcat (a, b, 3));
	printf ("%lu\n", strlcat (a, c1, 3));
}
*/
