/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:17:11 by azhadan           #+#    #+#             */
/*   Updated: 2023/05/30 12:28:26 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check(const char *str, int i, int *len, va_list args)
{
	if (str[i] == 'c')
		ft_putchar_fd_printf(va_arg(args, int), 1, len);
	else if (str[i] == 's')
		ft_putstr_fd_printf(va_arg(args, char *), 1, len);
	else if (str[i] == 'p')
		print_ptr_hex(va_arg(args, unsigned long int), len, 0);
	else if (str[i] == 'd')
		ft_putnbr_fd_printf(va_arg(args, int), 1, len);
	else if (str[i] == 'i')
		ft_putnbr_fd_printf(va_arg(args, int), 1, len);
	else if (str[i] == 'u')
		ft_unsigned_putnbr(va_arg(args, unsigned int), len);
	else if (str[i] == 'x')
		ft_puthex(va_arg(args, unsigned int), len, 0);
	else if (str[i] == 'X')
		ft_puthex(va_arg(args, unsigned int), len, 1);
	else if (str[i] == '%')
		ft_putchar_fd_printf('%', 1, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			check((char *)str, ++i, &len, args);
		else
			ft_putchar_fd_printf(str[i], 1, &len);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	printf("size:%d\n", printf("test %X\n", 0x4d));
// 	printf("size:%d\n", ft_printf("test %X\n", 0x4d));
// 	return (0);
// }
