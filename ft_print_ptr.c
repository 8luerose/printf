/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:52:41 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/08 21:15:47 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int *bytes)
{
	unsigned long long	v_ptr;

	v_ptr = (unsigned long long)ptr;
	if (v_ptr == 0)
	{
		ft_putstr("0x0", bytes);
		return ;
	}
	else
		ft_put_recul(v_ptr, "0123456789abcdef", bytes);
}

void	ft_put_recul(unsigned long long ptr, char *hex, int *bytes)
{
	char	c;

	if (*bytes == -1)
		return ;
	if (ptr == 0)
		ft_putstr("0x", bytes);
	else
	{
		ft_put_recul(ptr / 16, "0123456789abcdef", bytes);
		if (*bytes == -1)
			return ;
		c = hex[ptr % 16];
		ft_putchar(c, bytes);
		if (*bytes == -1)
			return ;
	}
}
