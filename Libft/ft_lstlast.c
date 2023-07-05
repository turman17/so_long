/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 02:00:41 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 02:33:54 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

// int	main(void)
// {
// 	t_list	n1;
// 	t_list	n2;
// 	t_list	n3;
// 	t_list	*start;
// 	t_list	*last;
// 	int		nb1;
// 	int		nb2;
// 	int		nb3;
// 	nb1 = 1;
// 	nb2 = 2;
// 	nb3 = 10;
// 	start = &n1;
// 	n1.content = &nb1;
// 	n2.content = &nb2;
// 	n3.content = &nb3;
// 	n1.next = &n2;
// 	n2.next = &n3;
// 	n3.next = NULL;
// 	last = ft_lstlast(start);
// 	printf("%d\n", *((int *)last->content));
// }
