/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:46:17 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/19 21:53:18 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;
	char	*e;

	i = 0;
	d = (char)c;
	e = (char *)s;
	while (e[i] != d && e[i])
		i++;
	if (e[i] == d || d == '\0')
		return (&e[i]);
	return (0);
}
/*
int	main(void)
{
	const char	a[] = "hola hola";
	int			b;

	b = 'o';
	printf ("%c\n", *ft_strchr(a, b));
	printf ("%c\n", *strchr(a, b));
	}
*/	
