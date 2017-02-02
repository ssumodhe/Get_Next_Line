/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:58:22 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/30 10:33:05 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (f == NULL || lst == NULL)
		return (NULL);
	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	start = new;
	while (lst != NULL)
	{
		if ((new->next = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		new->next = f(lst);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
