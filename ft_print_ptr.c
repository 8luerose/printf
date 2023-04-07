/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:52:41 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/07 22:40:03 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_h"

void	ft_putptr(unsigned long long ptr, int *bytes)
{
	if (ptr == 0)
	{
		ft_putstr("0x0", bytes);
		//*bytes += write(1, "0x0", 3);
		return ;
	}
	else
	{
		//ft_putstr("0x", bytes);
		ft_put_recul(ptr, "0123456789abcdef", bytes);
	}
}

void	ft_put_recul(unsigned long long ptr, char *hex, int *bytes)
{
	char	c;

	if (ptr == 0)
		ft_putstr("0x", bytes);
		//*bytes += write(1, "0x", 2);
	else
	{
		ft_put_recul(ptr / 16, "0123456789abcdef", bytes);
		c = hex[ptr % 16] + '0';
		ft_putchar(c, bytes);
		// ft_putchar(hex[ptr % 16], bytes);
	}
}