/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:41:29 by ana-maro          #+#    #+#             */
/*   Updated: 2023/09/26 18:19:05 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		end;
	int		i;

	end = ft_strlen(s1) - 1;
	i = 0;
	if (!set || !s1)
		return (0);
	while (i <= end && ft_strchr(set, s1[i]))
		i++;
	if (i > end)
		return (ft_strdup(""));
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	new = malloc(end - i + 2);
	if (!new)
		return (0);
	ft_strlcpy(new, &s1[i], end - i + 2);
	return (new);
}
