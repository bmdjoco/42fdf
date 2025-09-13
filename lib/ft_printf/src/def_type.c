/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:51:58 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/21 11:48:03 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	t_is_char(va_list args)
{
	int	val;

	val = va_arg(args, int);
	ft_putchar_fd_bis(val);
}

int	t_is_void_p(va_list args)
{
	void			*val;
	unsigned long	addr;
	int				l;

	val = va_arg(args, void *);
	addr = (unsigned long) val;
	if (addr == 0)
		return (ft_putstr_fd("(nil)", 1), 5);
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex_addr(addr);
	l = 0;
	while (addr >= 16)
	{
		l++;
		addr = addr / 16;
	}
	return (l + 3);
}

int	t_is_str(va_list args)
{
	char		*val;
	const char	*s;

	val = va_arg(args, char *);
	if (val == NULL)
		return (ft_putstr_fd("(null)", 1), 6);
	ft_putstr_fd(val, 1);
	s = val;
	return ((int) ft_strlen(s));
}

int	t_is_int(va_list args)
{
	long int	val;
	int			l;

	l = 0;
	val = va_arg(args, int);
	if (val == -2147483647)
		return (write(1, "-2147483647", 11), 11);
	ft_putnbr_fd(val, 1);
	if (val < 0)
	{
		l++;
		val = -val;
	}
	while (val >= 10)
	{
		val = val / 10;
		l++;
	}
	return (l + 1);
}

int	t_is_uns_int(va_list args)
{
	unsigned int	val;
	int				l;

	val = va_arg(args, unsigned int);
	ft_putnbr_uns(val);
	l = 0;
	while (val >= 10)
	{
		val = val / 10;
		l++;
	}
	return (l + 1);
}
