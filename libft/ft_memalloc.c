/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:25:00 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/24 11:46:09 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memalloc(size_t size)
{
	void	*x;

	if (!(x = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	return (ft_memset(x, '\0', size));
}
