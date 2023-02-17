/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:40:46 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 22:50:11 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft(void *c)
// {
// 	free(c);
// }

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}

// int	main(void)
// {
// 	t_list	*head;

// 	head = ft_lstnew("hello");
// 	// ft_lstdelone(head, ft);
// 	printf("%s", head->content);
// }
