/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:09:47 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 02:27:08 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*node;
// 	list = NULL;
// 	node = malloc(sizeof(t_list));
// 	node->content = (int *)malloc(sizeof(int));
// 	*(int *)node->content = 42;
// 	node->next = NULL;
// 	ft_lstadd_front(&list, node);
// 	printf("content:%d\n", *(int *)list->content);
// 	return (0);
// }
