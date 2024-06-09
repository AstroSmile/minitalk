/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:42:36 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/27 23:20:09 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	d;
	char	*e;

	len = ft_strlen(s);
	d = (char)c;
	e = (char *)s;
	if (c == '\0')
		return (&e[len]);
	while (len >= 0)
	{
		if (e[len] == d)
			return (&e[len]);
		len--;
	}
	return (0);
}
/*
int	main(void)
{
	const char	a[];
	int			b;

	a[] = "hola hola";
	b = 'o';
	printf ("%c\n", *ft_strrchr(a, b));
	printf ("%c\n", *strrchr(a, b));
}
*/
