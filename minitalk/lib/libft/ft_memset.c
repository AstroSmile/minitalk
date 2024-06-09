/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:04:09 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/19 02:19:38 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	n;
	char	*cast;

	cast = (char *)b;
	n = 0;
	while (n < len)
	{
		cast[n] = c;
		++n;
	}
	return ((void *)cast);
}
