/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:58:17 by taehkwon          #+#    #+#             */
/*   Updated: 2023/04/03 22:12:33 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_putchar(char c, int *bytes)
{
	int	check;

	check = write(1, &c, 1);
	if (check == -1)
		*bytes = -1
	else
		*bytes++;
}

void	ft_putstr(char *str, int *bytes)
{
	size_t	i;
	
	if (!s)
	{
		ft_pustr("(null)", bytes);
		return ;
	}
	else
	{
		i = 0;
		while(str[i])
			i++;
		*bytes += write(1, str, i);
	}
}

int 
