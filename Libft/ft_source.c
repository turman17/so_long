/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:10:06 by azhadan           #+#    #+#             */
/*   Updated: 2023/05/30 12:28:17 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd_printf(char c, int fd, int *len)
{
	write(fd, &c, 1);
	*len = *len + 1;
}

void	ft_putnbr_fd_printf(int n, int fd, int *len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd_printf('-', fd, len);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd_printf(nb / 10, fd, len);
	ft_putchar_fd_printf((nb % 10) + '0', fd, len);
}

void	ft_putstr_fd_printf(char *s, int fd, int *len)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd_printf(s[i], fd, len);
		i++;
	}
}

void	print_ptr_hex(unsigned long int ptr, int *len, int check)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (!ptr)
		ft_putstr_fd_printf("(nil)", 1, len);
	if (check == 0)
		ft_putstr_fd_printf("0x", 1, len);
	if (ptr >= 16)
		print_ptr_hex(ptr / 16, len, 1);
	ft_putchar_fd_printf(hex[ptr % 16], 1, len);
}

void	ft_unsigned_putnbr(unsigned int num, int *len)
{
	if (num >= 10)
		ft_unsigned_putnbr(num / 10, len);
	ft_putchar_fd_printf((num % 10) + '0', 1, len);
}
