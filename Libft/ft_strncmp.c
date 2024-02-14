/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:40:27 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/14 22:22:15 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "Hdllo, World!";
// 	s2 = "Hello, World!";
// 	printf("origin:%d\n", strncmp(s1, s2, 4));
// 	printf("    my:%d\n", ft_strncmp(s1, s2, 4));
// 	return (0);
// }
