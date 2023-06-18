/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:56:10 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 14:06:37 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp->next)
	{
		f(temp->content);
		temp = temp->next;
	}
	f(temp->content);
}

// void	ft_print_content(void *content)
// {
// 	printf("%s ", (char *)content);
// }
// int	main(void)
// {
// 	t_list	*list;
// 	list = ft_lstnew("Hello");
// 	ft_lstadd_front(&list, ft_lstnew("World"));
// 	ft_lstadd_front(&list, ft_lstnew("!"));
// 	ft_lstiter(list, ft_print_content);
// }
