/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:27:31 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/18 05:52:23 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	start_map(t_fil fil, char *str)
{

	if (ft_strchr(str, '#'))
		return (0);

}

int		ft_init(t_fil fil, char *line)
{
	
	return (0);
}

int		main(void)
{
	char	*line;
	t_fil	fil;

	fil.piece = NULL;
	start_map(fil, line);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_init(fil, line))
			filler(fil);
		free(line);
	}
	return (0);
}
