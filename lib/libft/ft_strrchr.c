/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:09:29 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/05 16:55:29 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int to_find)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (str[i])
	{
		if (str[i] == (char) to_find)
			res = (char *)&str[i];
		i++;
	}
	if (str[i] == (char) to_find)
		res = (char *)&str[i];
	return (res);
}
/*
#include <stdio.h>
int main(void)
{
	char *str = "/folder/image.jpg";
	printf("Original | %s\n", str);
	printf("Reponse | %s\n", ft_strrchr(str, '/'));

	return 0;
}
*/
