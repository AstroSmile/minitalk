/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:15:15 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/19 02:58:25 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (d == 0 && s == 0)
		return (0);
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len != 0)
		{
			d[len -1] = s[len -1];
			len--;
		}
	}
	return (dst);
}
/*int	main(void)
{
	char	d[] = "rodriguez";
	const char s[] = "anamaria";
	char	c[] = "rodriguez";

	printf("antes del memmove dst = %s, src = %s\n", d, s);
	ft_memmove(d, s, 2);
	printf("despues del memmove dst = %s,src =%s\n", d, s);
	memmove(c, s, 2);
	printf("memove original  dst = %s, src = %s\n", c, s);
	return (0);
}
*/
