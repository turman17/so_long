/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:51:37 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/15 00:10:17 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	char	*tdst;

	srclen = ft_strlen(src);
	tdst = dst;
	dstlen = 0;
	while (*tdst && dstlen < size)
	{
		tdst++;
		dstlen++;
	}
	if (dstlen == size)
		return (size + srclen);
	i = 0;
	while (i < size - dstlen - 1 && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

// int main()
// {
// 	char dest[20] = "Hello";
// 	char src[] = ", world!";
// 	size_t n = sizeof(dest) - ft_strlen(dest) - 1;
// 	size_t origin_result = strlcat(dest, src, n);
// 	size_t ft_result = ft_strlcat(dest, src, n);
// 	printf("Original result: %lu\n", origin_result);
// 	printf("    My result  : %lu\n", ft_result);
// 	return (0);
// }
