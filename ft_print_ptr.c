/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:52:41 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/07 05:30:25 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_h"

void	ft_putptr(unsigned long long ptr, int *bytes)
{
	if (ptr == 0)
	{
		*bytes += write(1, "0x0", 3);
		return ;
	}
	else
	{
		ft_putstr("0x", bytes);
		ft_put_recul(ptr, "0123456789abcdef", bytes);
	}
}

void	ft_put_recul(unsigned long long ptr, char *hex, int *bytes)
{
	if (ptr >= 16)
	{
		ft_put_recul(ptr, hex[ptr/16], bytes);
		ft_put_recul(ptr, hex[ptr%16], bytes);
	}
	ptr
	ft_putchar(hex[ptr])
}