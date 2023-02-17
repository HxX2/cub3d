/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:46:24 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 22:50:39 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

// int main()
// {
// 	t_list	*head;
// 	t_list	*sec;
// 	t_list	*new;

// 	head = ft_lstnew("hello");
// 	sec = ft_lstnew("world");
// 	new = ft_lstnew("!");

// 	head->next = sec;
// 	ft_lstadd_back(&head, new);
// 	printf("%s", (char *)ft_lstlast(head)->content);
// }