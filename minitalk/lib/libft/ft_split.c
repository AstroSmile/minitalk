/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:17:29 by ana-maro          #+#    #+#             */
/*   Updated: 2023/10/04 21:12:23 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_countwords(char const *s, char c)
{
	int		i;
	int		trigger;
	int		cont;
	char	**new;

	i = 0;
	trigger = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] != c && trigger == 0)
		{
			trigger = 1;
			cont++;
		}
		else if (s[i] == c)
			trigger = 0;
		i++;
	}
	if (cont == 0 || s[0] == '\0')
		return (ft_calloc(1, sizeof(char *)));
	new = (char **)malloc((cont + 1) * sizeof(char *));
	if (!new)
		return (0);
	return (new);
}

char	**ft_free(char **new, int i)
{
	while (i >= 0)
	{	
		free(new[i]);
		i--;
	}
	free(new);
	return (0);
}

size_t	ft_word_len(char const *s, char c)
{
	size_t	word_len;

	if (!ft_strchr(s, c))
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	word_len;
	int		i;

	i = 0;
	new = ft_countwords(s, c);
	if (!new)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_len = ft_word_len(s, c);
			new[i] = ft_substr(s, 0, word_len);
			if (!new[i])
				return (ft_free(new, i - 1));
			s += word_len;
			i++;
		}
	}
	new[i] = 0;
	return (new);
}
