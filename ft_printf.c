/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:17:29 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/03 22:12:59 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_argv(char c, va_list ap, int *bytes)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), bytes);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), bytes);
	else if (c == 'p')
		ft_put
	else if (c == 'd' || c == 'i')

	else if (c == 'u')
	
	else if (c == 'x')
	
	else if (c == 'X')

	else if (c == '%')

	else
		*bytes = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bytes;
	char	c;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			c = *(format + 1);
			ft_check_argv(c, ap, &bytes);
			if (bytes == -1)
				return (-1);
		}
		else
		{
			c = write(1, format, sizeof(char));
			if (c == -1)
				return (-1);
			bytes += c;
		}
		format++;
	}
	va_end(ap);
	return (bytes);
}
