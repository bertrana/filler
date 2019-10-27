/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:50:19 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:35:25 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_result(const char *s1, const char *s2, int i, int c)
{
	int y;
	int h;
	int u;

	h = 1;
	u = 0;
	while ((s1[i] != s2[c] && s1[i] && s2[c]) || h == 1)
	{
		h = 0;
		if (s1[0] != s2[0] || u++ >= 1)
			i++;
		if (s1[i] == s2[c])
		{
			y = i;
			while (s1[i++] == s2[c++])
				if (s2[c] == '\0')
					return ((char *)&s1[y]);
			h = 1;
			c = 0;
			i = y;
		}
	}
	return (NULL);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		c;
	char	*g;

	i = 0;
	c = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	g = ft_result(s1, s2, i, c);
	if (g != NULL)
		return (g);
	return (NULL);
}