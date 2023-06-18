/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 02:52:28 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 02:58:04 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }
// int	main(void)
// {
// 	t_list	*lst;
// 	char	*str;
// 	str = ft_strdup("hello");
// 	lst = ft_lstnew(str);
// 	ft_lstdelone(lst, del);
// 	return (0);
// }
