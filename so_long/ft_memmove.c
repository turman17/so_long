/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:57:59 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/18 16:26:14 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;

	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	if (new_dest == new_src)
		return (new_dest);
	if (new_dest < new_src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		new_dest[n] = new_src[n];
	return (new_dest);
}

// int main()
// {
// 	char dest[] = "123456789";
// 	char src[] = "987654321";
// 	memmove(dest, src, 3);
// 	char dest2[] = "123456789";
// 	ft_memmove(dest2, src, 3);
// 	printf("origin:%s\n", dest);
// 	printf("my:%s\n", dest2);
// }
