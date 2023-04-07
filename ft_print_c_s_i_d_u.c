/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s_i_d_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:58:17 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/07 20:39:50 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

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
		*bytes ++;
}

void	ft_putstr(char *str, int *bytes)
{
	size_t	i;

	if (str == NULL)
	{
		ft_pustr("(null)", bytes);
		return ;
	}
	else
	{
		i = 0;
		while (str[i])
			ft_putchar(str[i++], bytes);
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
	else if (nb >= 10)
		ft_putnbr(nb / 10, bytes);
	c = nb % 10 + '0';
	ft_putchar(c, bytes);
}

void	ft_putnbr_unsigned(unsigned int n, int *bytes)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr_unsigned((n / 10), bytes);
		//ft_putnbr_unsigned((n % 10), bytes);
	}
	else
	{
		c = n % 10 + '0';
		ft_putchar(c, bytes);
	}
}

void	ft_convert_base(unsigned int n, char *base, int *bytes)
{
	int				i;
	int				len;
	unsigned int	tmp;

	len = 0;
	while (base[len])
		len++;
	i = 0;
	/*
	while (n[i] & (n[i] >= '0' && n[i] <= '9'))
	{
		tmp = n[i];
		ft_putchar((base[tmp] - '0'), bytes);
		i++;
	}
	*/
}