/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-maro <ana-maro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:27:17 by ana-maro          #+#    #+#             */
/*   Updated: 2023/10/17 13:01:24 by ana-maro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*nod(t_list *new, t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	void	*c;
	t_list	*i;

	i = new;
	lst = lst->next;
	while (lst)
	{
		c = (f(lst->content));
		new->next = ft_lstnew(c);
		if (!new->next)
		{
			ft_lstclear(&i, del);
			free(c);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (i);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*c;

	if (!f || !del || !lst)
		return (NULL);
	c = f(lst->content);
	new = ft_lstnew(c);
	if (!new)
	{
		free(c);
		return (0);
	}
	new = nod(new, lst, f, del);
	return (new);
}
