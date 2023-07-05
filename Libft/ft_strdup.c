/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:48:25 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/15 13:28:53 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sc;

	sc = (char *)malloc(ft_strlen(s) + 1);
	if (!sc)
		return (NULL);
	ft_memcpy(sc, s, (ft_strlen(s) + 1));
	return (sc);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*copy;
// 	char	*origin;
// 	str = "Hello, world!";
// 	copy = ft_strdup(str);
// 	origin = strdup(str);
// 	printf("    my:%s\n", copy);
// 	printf("origin:%s\n", origin);
// 	return (0);
// }
