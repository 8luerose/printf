/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:42:27 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/07 22:56:41 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *format, ...);
static void	ft_check_argv(char c, va_list ap, int *bytes);
void		ft_putchar(char c, int *bytes);
void		ft_putstr(char *str, int *bytes);
void		ft_putnbr(int n, int *bytes);
void		ft_putnbr_unsigned(unsigned int n, int *bytes);
void		ft_convert_base(unsigned int num, char *hex, int *bytes);
void		ft_putptr(unsigned long long ptr, int *bytes);
void		ft_put_recul(unsigned long long ptr, char *hex, int *bytes);

#endif