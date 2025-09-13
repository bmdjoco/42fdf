/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:33:48 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/01 12:41:23 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*space;
	size_t			i;

	i = 0;
	space = (unsigned char *)s;
	while (i < n)
	{
		space[i] = (unsigned char) 0;
		i++;
	}
}
/*
#include <stdio.h>
int main(void) {
	char	test[] = "Hola";
	printf(">| %s\n", test);
	ft_bzero( test, (size_t) (sizeof(char)*5));
	printf("<| %s\n", test);

	return 0;
}
*/
