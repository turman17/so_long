/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:41:04 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 02:30:33 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*temp;

	temp = lst;
	len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

// int	main(void)
// {
// 	t_list	n1;
// 	t_list	n2;
// 	t_list	n3;
// 	t_list	*start;
// 	int		nb1;
// 	int		nb2;
// 	int		nb3;
// 	nb1 = 1;
// 	nb2 = 2;
// 	nb3 = 3;
// 	start = &n1;
// 	n1.content = &nb1;
// 	n2.content = &nb2;
// 	n3.content = &nb3;
// 	n1.next = &n2;
// 	n2.next = &n3;
// 	n3.next = NULL;
// 	printf("%d\n", ft_lstsize(start));
// }
