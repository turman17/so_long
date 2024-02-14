/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_source.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhadan <azhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:54:56 by azhadan           #+#    #+#             */
/*   Updated: 2023/05/30 12:28:13 by azhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int num, int *len, int up_or_low)
{
	char	*hex;
	char	*hex_up;

	hex = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	if (num >= 16)
		ft_puthex(num / 16, len, up_or_low);
	if (up_or_low)
		ft_putchar_fd_printf(hex_up[num % 16], 1, len);
	else
		ft_putchar_fd_printf(hex[num % 16], 1, len);
}
