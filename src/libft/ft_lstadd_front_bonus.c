/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:06:55 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 22:50:22 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new -> next = *lst;
		*lst = new;
	}
}

// int main()
// {
// 	t_list *head;
// 	t_list	*sec;
// 	t_list	*new;

// 	head = ft_lstnew("hello");
// 	sec = ft_lstnew("world");
// 	new = ft_lstnew("ghita");
// 	head->next = sec;
// 	ft_lstadd_front(&head, new);
// 	printf("%s",(char *) new->next->content);
// }