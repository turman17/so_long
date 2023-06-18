/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:23:51 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/16 19:26:47 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	s_len -= start;
	if (s_len > len)
		s_len = len;
	sub = (char *)malloc(s_len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, s_len);
	sub[s_len] = '\0';
	return (sub);
}

// int	main(void)
// {
// 	printf("%s\n", ft_substr("test", 5, 2));
// 	return (0);
// }
