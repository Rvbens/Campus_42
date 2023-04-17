/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:18:42 by rchaves-          #+#    #+#             */
/*   Updated: 2022/12/18 22:17:46 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*clean(t_list *start, void (*del)(void *), void *cnt)
{
	del(cnt);
	ft_lstclear(&start, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*node;
	void	*cnt;

	if (!lst)
		return (0);
	cnt = f(lst->content);
	start = ft_lstnew(cnt);
	if (!start)
		return (clean(start, del, cnt));
	node = start;
	while (lst->next)
	{
		cnt = f(lst->next->content);
		node->next = ft_lstnew(cnt);
		if (!node->next)
			return (clean(start, del, cnt));
		lst = lst->next;
		node = node->next;
	}
	return (start);
}
