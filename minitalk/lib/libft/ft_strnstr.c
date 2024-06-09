/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:05:31 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/19 01:39:42 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		i = 0;
		temp = j;
		while (haystack[j] == needle[i] && j < len
			&& haystack[j] && needle[i])
		{
			i++;
			j++;
		}
		if (needle[i] == '\0')
			return ((char *)(&haystack[temp]));
		j = temp + 1;
	}
	return (NULL);
}
/*
int	main()
{
	size_t n;
	const char a[] = "automovil";
	const char a2[] = "automovil";
	const char b[] = "m";

	n = 4;
	printf("%s\n", ft_strnstr(a, b, n));
	printf("%s\n", strnstr(a2, b, n));
}
*/
