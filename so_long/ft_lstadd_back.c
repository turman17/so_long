/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 02:10:48 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 02:46:35 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

// int	main(void)
// {
// 	t_list	*lst;
// 	int		a;
// 	int		b;
// 	int		c;
// 	t_list	*check;
// 	lst = NULL;
// 	a = 1;
// 	b = 2;
// 	c = 3;
// 	ft_lstadd_back(&lst, ft_lstnew(&a));
// 	ft_lstadd_back(&lst, ft_lstnew(&b));
// 	ft_lstadd_back(&lst, ft_lstnew(&c));
// 	check = lst;
// 	while (check != NULL)
// 	{
// 		printf("%d\n", *(int *)check->content);
// 		check = check->next;
// 	}
// 	printf("\n");
// 	return (0);
// }
