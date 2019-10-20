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

void	init_struct(t_filler fil, char *line)
{
	int h;
	int w;

	while (get_next_line(0, &line) && !ft_strstr(line, "Plateau"))
		free(line);
	w = ft_atoi(ft_strchr(line, ' '));
	h = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	printf("h = %d\nw = %d\n", h, w);
}

int 	main(void)
{
	char		*line;
	t_filler	filler;

	line = NULL;
	while (get_next_line(0, &line) && (!ft_strstr(line, "pbondoer") ||
		line[0] != '$'))
		free(line);
	filler.player = (char)(line[10] == '1' ? 'O' : 'X');
	filler.enemy = (char)(line[10] == '1' ? 'X' : 'O');
	printf("player = %c\nenemy = %c\n", filler.player, filler.enemy);
	init_struct(filler, line);
	return (0);
}
