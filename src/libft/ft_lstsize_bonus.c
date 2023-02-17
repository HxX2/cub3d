/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:17:42 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/05 20:23:09 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

// int main()
// {
// 	t_list	*head;
// 	t_list	*sec;
// 	t_list	*new;

// 	head = ft_lstnew("hello");
// 	sec = ft_lstnew("hello");
// 	new = ft_lstnew("hello");
// 	head->next = sec;
// 	sec->next = new;
// 	printf("%d",ft_lstsize(head));
// }