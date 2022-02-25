#include "libft.h"

char	*ft_strfreejoin(char *s1, char *s2)
{
	char		*s;
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
