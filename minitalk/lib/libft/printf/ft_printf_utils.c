/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:54:29 by ana-maro          #+#    #+#             */
/*   Updated: 2023/11/05 19:40:23 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar(char c, int *len)
{
	if (write(1, &c, 1) == -1)
		*len = -1;
	else
		*len += 1;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = -1;
	if (!s)
		ft_putstr("(null)", len);
	else
		while (s[++i] && *len != -1)
			ft_putchar(s[i], len);
}

void	ft_pointer(unsigned long long nbr, int *len)
{
	ft_putstr("0x", len);
	if (nbr > 9223372036854775807)
	{
		ft_putnbr_base(nbr / 16, "0123456789abcdef", len);
		ft_putnbr_base(nbr % 16, "0123456789abcdef", len);
	}
	else
		ft_putnbr_base(nbr, "0123456789abcdef", len);
}

void	ft_putnbr_base(int long long nbr, char *base, int *len)
{
	int	size_base;

	size_base = ft_strlen(base);
	if (*len == -1)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-', len);
		ft_putnbr_base(-nbr, base, len);
	}
	else if (nbr >= size_base)
	{
		ft_putnbr_base(nbr / size_base, base, len);
		ft_putnbr_base(nbr % size_base, base, len);
	}
	else
		ft_putchar(base[nbr], len);
}
