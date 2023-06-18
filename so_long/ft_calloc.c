/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:23:45 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 14:43:36 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	pointer = malloc(size * nmemb);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, size * nmemb);
	return (pointer);
}

// int	main(void)
// {
// 	char	*ptr1;
// 	char	*ptr2;
// 	ptr1 = calloc(10, sizeof(char));
// 	ptr2 = ft_calloc(10, sizeof(char));
// 	printf("origin:%s\n", ptr1);
// 	printf("    my:%s\n", ptr2);
// 	free(ptr1);
// 	free(ptr2);
// 	return (0);
// }
