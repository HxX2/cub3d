/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:25:00 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 22:49:58 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main()
// {
// 	t_list	*head;
// 	t_list	*sec;
// 	t_list	*tail;

// 	head = ft_lstnew("hello");
// 	sec = ft_lstnew("world");
// 	tail = ft_lstnew("!");
// 	head->next = sec;
// 	sec->next = tail;
// 	printf("%s", (char *)ft_lstlast(head)->content);
// }
