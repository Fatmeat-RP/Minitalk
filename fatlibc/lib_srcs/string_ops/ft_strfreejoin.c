/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:59:28 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/28 16:59:28 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfreejoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	s = malloc(j + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	if (j)
	{
		while (i < j)
		{
			s[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (*s2++)
	{
		s[i] = *s2;
		i++;
	}
	s[i] = 0;
	return (s);
}
