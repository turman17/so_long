/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.C                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:16:51 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/14 21:46:12 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n != 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str;

// 	str = "Hello, world!";
// 	char *ptr1, *ptr2;
// 	ptr1 = memchr(str, 'w', 10);
// 	ptr2 = ft_memchr(str, 'w', 10);
// 	printf("origin:%p\n", ptr1);
// 	printf("    my:%p\n", ptr2);
// }
