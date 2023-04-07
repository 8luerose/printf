/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:52:41 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/07 22:58:22 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long long ptr, int *bytes)
{
	if (ptr == 0)
	{
		ft_putstr("0x0", bytes);
		return ;
	}
	else
		ft_put_recul(ptr, "0123456789abcdef", bytes);
}

void	ft_put_recul(unsigned long long ptr, char *hex, int *bytes)
{
	char	c;

	if (ptr == 0)
		ft_putstr("0x", bytes);
	else
	{
		ft_put_recul(ptr / 16, "0123456789abcdef", bytes);
		c = hex[ptr % 16] + '0';
		ft_putchar(c, bytes);
	}
}
// ft_putchar(hex[ptr % 16], bytes);