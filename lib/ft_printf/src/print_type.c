/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:54:41 by bdjoco            #+#    #+#             */
/*   Updated: 2025/06/19 18:04:58 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_uns(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putnbr_fd(n % 10, 1);
	}
}

void	ft_putnbr_hex(int n)
{
	unsigned int	un;

	un = (unsigned int) n;
	if (un >= 16)
		ft_putnbr_hex(un / 16);
	if ((un % 16) < 10)
		ft_putchar_fd((un % 16) + '0', 1);
	else
		ft_putchar_fd((un % 16) - 10 + 'a', 1);
}

void	ft_putnbr_hex_up(int n)
{
	unsigned int	un;

	un = (unsigned int) n;
	if (un >= 16)
		ft_putnbr_hex_up(un / 16);
	if ((un % 16) < 10)
		ft_putchar_fd((un % 16) + '0', 1);
	else
		ft_putchar_fd((un % 16) - 10 + 'A', 1);
}

void	ft_putnbr_hex_addr(unsigned long un)
{
	if (un >= 16)
		ft_putnbr_hex_addr(un / 16);
	if ((un % 16) < 10)
		ft_putchar_fd((un % 16) + '0', 1);
	else
		ft_putchar_fd((un % 16) - 10 + 'a', 1);
}

void	print_address(void *ptr)
{
	unsigned long	addr;
	int				i;

	addr = (unsigned long) ptr;
	ft_putstr_fd("0x", 1);
	i = (int) addr;
	ft_putnbr_hex(i);
}
