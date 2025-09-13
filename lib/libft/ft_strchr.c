/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:09:47 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/05 16:50:14 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int to_find)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char) to_find)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == (char) to_find)
		return ((char *) &str[i]);
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
	char *str = "/folder/image.jpg";
	printf("Original | %s\n", str);
	printf("Reponse | %s\n", ft_strchr(str, '/'));

	return 0;
}
*/
