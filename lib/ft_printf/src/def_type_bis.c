/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_type_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:04:53 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/15 11:22:18 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	t_is_hex(va_list args)
{
	int				val;
	int				l;
	unsigned int	un;

	val = va_arg(args, int);
	ft_putnbr_hex(val);
	un = (unsigned int) val;
	l = 0;
	while (un >= 16)
	{
		l++;
		un = un / 16;
	}
	return (l + 1);
}

int	t_is_hex_up(va_list args)
{
	int				val;
	int				l;
	unsigned int	un;

	val = va_arg(args, int);
	ft_putnbr_hex_up(val);
	un = (unsigned int) val;
	l = 0;
	while (un >= 16)
	{
		l++;
		un = un / 16;
	}
	return (l + 1);
}
