/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:08:53 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/06/08 16:58:38 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*element;
	t_list	*temp;

	newlst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		temp = f(lst->content);
		element = ft_lstnew(temp);
		if (!element)
		{
			del(temp);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&newlst, element);
			lst = lst->next;
		}
	}
	return (newlst);
}
