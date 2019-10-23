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

void    read_map(t_map *map, char *line)
{
    int	i;

    i = 0;
	if (!(map->map = (char **)malloc(sizeof(char *) * (map->y + 1))))
		exit(1);
	map->map[map->y] = NULL;
    while(get_next_line(STDIN_FILENO, &line) && !ft_strstr(line, "000 "))
        free(line);
    while (i < map->x && get_next_line(STDIN_FILENO, &line))
	{
		map->map[map->y] = ft_strdup(line + 4);
		free(line);
	}
}

void	init_struct(t_filler *f, char *line)
{
	int	w;
	int	h;

	w = ft_atoi(ft_strchr(line, ' '));
	h = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	f->board->y = w;
    f->board->x = h;

	printf("y = %d\nx = %d\n", w, h);
	read_map(f->board, line);
}

void	ft_init(t_filler *filler, char *line)
{
	filler->player = (char)(line[10] == '1' ? 'O' : 'X');
	filler->enemy = (char)(line[10] == '1' ? 'X' : 'O');
	if (!(filler->board = (t_map *)malloc(sizeof(t_map))) ||
		!(filler->piece = (t_map *)malloc(sizeof(t_map))))
		exit(1);
}

int 	main(void)
{
	char		*line;
	t_filler	*filler;

	filler = (t_filler *)malloc(sizeof(t_filler));
	while(get_next_line(STDIN_FILENO, &line))
	{
		if ((ft_strstr(line, PLAYER_S) && line[0] == '$'))
			ft_init(filler, line);
		else if (ft_strstr(line, "Plateau"))
			init_struct(filler, line);
//		else if (ft_strstr(line, "Piece "))
//		{
//			game();
//			free_arrays();
//		}
		free(line);
	}
	return (0);
}
