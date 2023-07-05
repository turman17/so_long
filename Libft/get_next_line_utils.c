/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:34:30 by azhadan           #+#    #+#             */
/*   Updated: 2023/05/29 23:07:53 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strle_gnl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

int	ft_check(char *to_check)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (to_check[i[1]])
	{
		if (i[0])
			to_check[i[2]++] = to_check[i[1]];
		if (to_check[i[1]] == '\n')
			i[0] = 1;
		to_check[i[1]++] = '\0';
	}
	return (i[0]);
}

char	*ft_gnl_join(char *s1, char *s2)
{
	char	*str;
	int		i[3];

	i[0] = ft_strle_gnl(s1) + ft_strle_gnl(s2);
	i[1] = 0;
	i[2] = -1;
	str = (char *)malloc(sizeof(char) * (i[0] + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i[1]])
	{
		str[i[1]] = s1[i[1]];
		i[1]++;
	}
	while (s2[++i[2]])
	{
		str[i[1]++] = s2[i[2]];
		if (s2[i[2]] == '\n')
			break ;
	}
	str[i[1]] = '\0';
	free(s1);
	return (str);
}
