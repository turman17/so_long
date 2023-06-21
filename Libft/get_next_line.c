/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:17:11 by azhadan           #+#    #+#             */
/*   Updated: 2023/05/29 20:53:17 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		i = 0;
		if (fd >= 0 && fd <= FOPEN_MAX)
		{
			while (buffer[fd][i])
				buffer[fd][i++] = '\0';
		}
		return (NULL);
	}
	str = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_gnl_join(str, buffer[fd]);
		if (ft_check(buffer[fd]))
			break ;
	}
	return (str);
}

// int	main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	char	*out_put;
// 	int		i;

// 	fd = open("get_next_line.c", O_RDONLY);
// 	fd2 = open("get_next_line_utils.c", O_RDONLY);
// 	i = 2;
// 	while (i > 0)
// 	{
// 		out_put = get_next_line(fd);
// 		if (out_put)
// 			printf("%s\n", out_put);
// 		i--;
// 	}
// 	i = 2;
// 	while (i > 0)
// 	{
// 		out_put = get_next_line(fd2);
// 		if (out_put)
// 			printf("%s\n", out_put);
// 		i--;
// 	}
// }
