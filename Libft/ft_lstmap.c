/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:07:41 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 14:22:33 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}

// void	*add(void *str)
// {
// 	char	*new_str;
// 	new_str = ft_strjoin((char *)str, "!");
// 	return ((void *)new_str);
// }
// void	del(void *str)
// {
// 	free(str);
// }
// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*new_list;
// 	list = ft_lstnew("Hello");
// 	ft_lstadd_back(&list, ft_lstnew("world"));
// 	new_list = ft_lstmap(list, add, del);
// 	while (new_list)
// 	{
// 		printf("%s\n", (char *)new_list->content);
// 		new_list = new_list->next;
// 	}
// }
