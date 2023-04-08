/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s_i_d_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:58:17 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/08 21:10:24 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *bytes)
{
	int	check;

	check = write(1, &c, 1);
	if (check == -1)
	{
		*bytes = -1;
		return ;
	}
	else
		(*bytes)++;
}

void	ft_putstr(char *str, int *bytes)
{
	size_t	i;

	if (str == NULL)
	{
		ft_putstr("(null)", bytes);
		return ;
	}
	else
	{
		i = 0;
		while (str[i])
		{
			ft_putchar(str[i++], bytes);
			if (*bytes == -1)
				return ;
		}
	}
}

void	ft_putnbr(int n, int *bytes)
{
	char		c;
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		ft_putchar('-', bytes);
		nb = -nb;
	}
	if (*bytes == -1)
		return ;
	if (nb >= 10)
		ft_putnbr(nb / 10, bytes);
	if (*bytes == -1)
		return ;
	c = nb % 10 + '0';
	ft_putchar(c, bytes);
	if (*bytes == -1)
		return ;
}

void	ft_putnbr_unsigned(unsigned int n, int *bytes)
{
	char	c;

	if (n >= 10)
		ft_putnbr_unsigned((n / 10), bytes);
	if (*bytes == -1)
		return ;
	c = n % 10 + '0';
	ft_putchar(c, bytes);
	if (*bytes == -1)
		return ;
}

void	ft_convert_base(unsigned int num, char *hex, int *bytes)
{
	char	c;

	if (*bytes == -1)
		return ;
	if (num >= 16)
		ft_convert_base(num / 16, hex, bytes);
	if (*bytes == -1)
		return ;
	c = hex[num % 16];
	ft_putchar(c, bytes);
	if (*bytes == -1)
		return ;
}
// c = hex[num % 16] + '0';

/*

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

*/