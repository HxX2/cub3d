/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:26:19 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 22:14:08 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elm;

	new_lst = NULL;
	if (!lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		new_elm = ft_lstnew(f(lst->content));
		if (!new_elm)
		{
			ft_lstclear(&new_elm, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elm);
		lst = lst->next;
	}
	return (new_lst);
}
// void	*f(void *c)
// {
// 	c = ft_strdup("modified");
// 	return c;
// }

// void	del(void *s)
// {
// 	free (s);
// }

// void ft_affiche(t_list *nudes)
// {
// 		while (node->next)
// 	{
// 		printf("%s", (char *)node->content);
// 		node = node->next;
// 	}
// }

// int	main()
// {
// 	t_list	*head = NULL;

// 	int	i;

// 	while (i < 20)
// 	{
// 		ft_lstadd_back(&head,ft_lstnew(ft_strdup("so yeah ")));
// 		i++;
// 	}
// 	t_list *node;
// 	node = ft_lstmap(head,f,del);
// 	 ft_affiche(node);
// }