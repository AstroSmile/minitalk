/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:54:06 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/19 22:38:53 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void		*ptr;
	int			temp;

	temp = ft_strlen(s1);
	ptr = (void *)malloc(temp + 1);
	if (ptr == NULL)
		return (0);
	ft_memcpy(ptr, s1, temp + 1);
	return (ptr);
}
/*
int	main()
{
	char	str[] = "cadena";

	printf("%s\n", ft_strdup(str));
	printf("%s\n", strdup(str));
}
*/
