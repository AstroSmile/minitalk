/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:04:35 by ana-maro          #+#    #+#             */
/*   Updated: 2023/11/05 19:38:37 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	check_type(char c, va_list va, int *len)
{
	if (c == '%')
		ft_putchar('%', len);
	else if (c == 'c')
		ft_putchar(va_arg(va, int), len);
	else if (c == 's')
		ft_putstr(va_arg(va, char *), len);
	else if (c == 'p')
		ft_pointer(va_arg(va, unsigned long long), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(va, int), "0123456789", len);
	else if (c == 'u')
		ft_putnbr_base(va_arg(va, unsigned int), "0123456789", len);
	else if (c == 'x')
		ft_putnbr_base(va_arg(va, unsigned int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_base(va_arg(va, unsigned int), "0123456789ABCDEF", len);
	else
		*len = -1;
}

int	ft_printf(char const *f, ...)
{
	va_list	format;
	int		len;

	len = 0;
	va_start(format, f);
	while (*f && len != -1)
	{
		if (*f == '%')
		{
			f++;
			check_type(*f, format, &len);
		}
		else
			ft_putchar(*f, &len);
		f++;
	}
	va_end(format);
	return (len);
}

// int main()
// {
//     int j;
//     j = ft_printf("%d\n", -10);
// }
