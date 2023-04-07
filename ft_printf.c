/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:17:29 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/07 20:36:46 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_argv(char c, va_list ap, int *bytes)
{
	if (c == 'c')
		ft_putchar((char)va_arg(ap, int), bytes);
	else if (c == 's')
		ft_putstr((char *)va_arg(ap, char *), bytes);
	else if (c == 'p')
		ft_putptr(va_arg(ap, unsigned long long), bytes);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), bytes);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int), bytes);
	else if (c == 'x')
		ft_atoi_base(va_arg(ap, unsigned int), "0123456789abcdef", bytes);
	else if (c == 'X')
		ft_atoi_base(va_arg(ap, unsigned int), "0123456789ABCDEF", bytes);
	else if (c == '%')
		ft_putchar('%', bytes);
	else
		*bytes = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bytes;
	int		i;

	va_start(ap, format);
	bytes = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_check_argv(format[++i], ap, &bytes);
		else
			bytes += write(1, &format[i], 1);
		if (bytes == -1)
		{
			va_end(ap);
			return (bytes);
		}
		i++;
	}
	va_end(ap);
	return (bytes);
}

/*
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bytes;
	int		past_bytes;
	size_t	i;

	va_start(ap, format);
	bytes = 0;
	i = 0;
	while (format[i])
	{
		past_bytes = bytes;
		if (format[i] == '%')
			ft_check_argv(format[++i], ap, &bytes);
		else
			bytes += write(1, &format[i], 1);
		if (past_bytes > bytes)
		{
			bytes = -1;
			va_end(ap);
			return (bytes);
		}
		i++;
	}
	va_end(ap);
	return (bytes);
}
*/
