/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:15:09 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 22:08:32 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	f(void *c)
// {
// 	char	*str;

// 	str = (char *)c;
// 	ft_strlcpy(str, "hello", 6);
// }

// int	main(void)
// {
// 	t_list	*head;

// 	head = ft_lstnew("122345669");
// 	ft_lstiter(head, f);
// 	printf("%s", head->content);
// }
