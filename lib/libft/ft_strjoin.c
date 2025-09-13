/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:36:51 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/02 11:43:29 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	int		i;
	char	*res;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(sizeof(char) * l);
	if (res == NULL)
		return (NULL);
	l = 0;
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	res[ft_strlen(s1) + i] = '\0';
	return (res);
}
/*
#include <stdio.h>
int main(void)
{
	char *s1 = "It will";
	char *s2 = " work perfectly!";
	char *res;

	res = ft_strjoin(s1, s2);
	if (res == NULL)
		return (1);
	printf("string 1 | %s\n", s1);
	printf("string 2 | %s\n", s1);
	printf("string join | %s\n", res);
	free(res);
	return 0;
}
*/
