/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 02:59:05 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 13:54:18 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*main;

	if (!lst || !del)
		return ;
	main = *lst;
	while (main)
	{
		next = main->next;
		ft_lstdelone(main, del);
		main = next;
	}
	*lst = NULL;
}

// void	del(void *content)
// {
// 	free(content);
// }
// int	main(void)
// {
// 	t_list	*list;
// 	list = ft_lstnew("Hello");
// 	ft_lstadd_front(&list, ft_lstnew("World"));
// 	ft_lstadd_front(&list, ft_lstnew("!"));
// 	while (list != NULL)
// 	{
// 		printf("%s\n", (char *)list->content);
// 		list = list->next;
// 	}
// 	ft_lstclear(&list, del);
// 	while (list != NULL)
// 	{
// 		printf("%s\n", (char *)list->content);
// 		list = list->next;
// 	}
// 	return (0);
// }
