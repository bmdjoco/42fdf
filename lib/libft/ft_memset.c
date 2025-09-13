/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:30:03 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/05 16:57:11 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)pointer;
	while (count > 0)
	{
		*tmp = (unsigned char) value;
		count--;
		tmp++;
	}
	return (pointer);
}
/*
#include <stdio.h>
int main() {
    int a [] = { 54, 85, 20, 63, 21 };

    memset( a, 0, (size_t)(sizeof(int)*5));
	printf("{%d, %d, %d, %d, %d}",
		a[0],
		a[1],
		a[2],
		a[3],
		a[4]
	);

    return 0;
}
*/
