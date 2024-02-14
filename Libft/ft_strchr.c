/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:51:02 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/14 21:43:04 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str;

// 	str = "Hello, world!";
// 	char *ptr1, *ptr2;
// 	ptr1 = strchr(str, 'w');
// 	ptr2 = ft_strchr(str, 'w');
// 	printf("origin:%p\n", ptr1);
// 	printf("    my:%p\n", ptr2);
// }
