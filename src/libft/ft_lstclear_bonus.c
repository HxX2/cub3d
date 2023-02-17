/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:58:41 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/05 18:54:12 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				tmp = *lst;
				*lst = (*lst)->next;
				del(tmp->content);
				free(tmp);
			}
		}
	}
}

// void	del(void *c)
// {
// 	free (c);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*sec;

// 	head = ft_lstnew(("hello"));
// 	sec = ft_lstnew(("hello"));
// 	head->next = sec;
// 	ft_lstclear(&head, del);
// 	printf("%s", head->content);
// }