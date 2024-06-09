/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:39:48 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/19 03:53:18 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (src[i] && i < dstsize -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
			i++;
	return (i);
}
/*int	main(void)
{
	char		d[] = "hola";
	char		d1[] = "hola";
	const char 	s[] = "Ana";

	printf ("%zu\n", ft_strlcpy(d, s, 2));
	printf ("%zu\n", strlcpy(d1, s, 2));
}
*/
