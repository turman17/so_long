/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:50:02 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/15 00:06:17 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <string.h>
// int	main(void)
// {
// 	const char *find = "The quick brown fox";
//     const char *need1 = "brown";
//     const char *need2 = "quick brown";
//     const char *need3 = "fox";
//     const char *need4 = "The quick brown fox jumps over the lazy dog";

//     printf("    my: %s\n", ft_strnstr(find, need1, ft_strlen(find)));
//     printf("origin: %s\n", strnstr(find, need1, strlen(find)));
//     printf("    my: %s\n", ft_strnstr(find, need2, ft_strlen(find)));
// 	printf("origin: %s\n", strnstr(find, need2, strlen(find)));
//     printf("    my: %s\n", ft_strnstr(find, need3, ft_strlen(find)));
// 	printf("origin: %s\n", strnstr(find, need3, strlen(find)));
//     printf("    my: %s\n", ft_strnstr(find, need4, ft_strlen(find)));
// 	printf("origin: %s\n", strnstr(find, need4, strlen(find)));
// 	return (0);
// }
