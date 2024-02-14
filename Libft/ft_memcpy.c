/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:35:49 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/13 21:57:36 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*c_dst;
	char			*c_src;
	unsigned long	i;

	i = 0;
	c_dst = (char *)dest;
	c_src = (char *)src;
	if (c_dst == NULL && c_src == NULL)
		return (NULL);
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return ((void *)c_dst);
}

/* int main()
{
	char dest[] = "123456789";
	char src[] = "987654321";
	memcpy(dest, src, 3);
	char dest2[] = "123456789";
	ft_memcpy(dest2, src, 3);

	printf("origin:%s\n", dest); 
	printf("my:%s\n", dest2);
} */
