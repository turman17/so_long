/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:57:44 by azhadan           #+#    #+#             */
/*   Updated: 2023/04/14 15:09:09 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*ch;

	ch = s;
	i = 0;
	while (i < n)
	{
		ch[i] = '\0';
		i++;
	}
}

/* int	main(void)
{
	char	test[] = "123456789";
	char	test2[] = "123456789";
	bzero(test, 0);
	ft_bzero(test2, 0);
	printf("Origin:%s\n", test);
	printf("My:%s\n", test2);
	return (0);
} */
