/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:55:01 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/13 23:44:56 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*ch;

	ch = s;
	i = 0;
	while (i < n)
		ch[i++] = c;
	return ((void *)ch);
}

/* int main(int argc, char **argv)
{
	int c;
	size_t n;
	char x[20] = "ewreerwgbt";
	c = '?';
	n = 3;
	printf("origin:%s\n", memset(x, c, n));
	printf("my:%s\n", ft_memset(x, c, n));
	return (0);
} */
