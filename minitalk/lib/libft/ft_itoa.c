/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:52:07 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/26 21:45:54 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numbercount(int d)
{
	int	count;

	count = 1;
	if (d < 0)
	{
		if (d == -2147483648)
			return (11);
		d *= -1;
		count++;
	}
	while (d > 9)
	{
		d /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numbercount(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = 0;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}	
	return (str);
}
