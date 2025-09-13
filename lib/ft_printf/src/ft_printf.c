/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:58:57 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/21 13:16:25 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	is_implement(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i'
		|| c == 'p' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	is_valid(const char *str)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '%')
			l++;
		else
		{
			if (!str[i + 1])
				return (-1);
			if (!is_implement(str[i + 1]))
				return (-1);
			i++;
		}
		i++;
	}
	return (l);
}

int	convert_par(va_list pars, char t)
{
	if (t == 'c')
		return (t_is_char(pars), 1);
	else if (t == 's')
		return (t_is_str(pars));
	else if (t == 'd' || t == 'i')
		return (t_is_int(pars));
	else if (t == 'u')
		return (t_is_uns_int(pars));
	else if (t == 'x')
		return (t_is_hex(pars));
	else if (t == 'X')
		return (t_is_hex_up(pars));
	else if (t == 'p')
		return (t_is_void_p(pars));
	else
		return (ft_putchar_fd('%', 1), 1);
}

int	ft_printf(const	char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	if (!str)
		return (-1);
	len = is_valid(str);
	if (len == -1)
		return (0);
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1);
		else
			len += convert_par(args, str[i + 1]);
		if (str[i] == '%')
			i++;
		i++;
	}
	return (va_end(args), len);
}
