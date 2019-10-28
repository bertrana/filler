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

void	read_map(t_filler *f, char *line)
{
	int	w;
	int	h;
	int	i;

	i = 0;
	if (!(f->board = (t_map *)malloc(sizeof(t_map))))
		exit(1);
	w = ft_atoi(ft_strchr(line, ' '));
	h = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	f->board->y = w;
	f->board->x = h;
	if (!(f->B_MAP = (char **)malloc(sizeof(char *) * (f->board->y + 1))))
		exit(1);
	f->B_MAP[f->board->y] = NULL;
	while (get_next_line(STDIN_FILENO, &line) && !ft_strstr(line, "0123"))
		free(line);
	free(line);
	while (i < f->board->y && get_next_line(STDIN_FILENO, &line))
	{
		f->B_MAP[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
}

void	take_char(t_filler *filler, char *line)
{
	line = ft_strchr(line, 'p');
	line++;
	filler->player = (char)(*line == '1' ? 'o' : 'x');
	filler->enemy = (char)(*line == '1' ? 'x' : 'o');
}

void	free_arrays(t_filler *f)
{
	int	i;

	i = 0;
	while (i < f->board->y)
	{
		free(f->B_MAP[i]);
		i++;
	}
	free(f->B_MAP);
	free(f->board);
	i = 0;
	while (i < f->piece->y)
	{
		free(f->P_MAP[i]);
		i++;
	}
	free(f->P_MAP);
	free(f->piece);
}

void	read_piece(t_filler *f, char *line)
{
	int i;

	i = 0;
	if (!(f->piece = (t_map *)malloc(sizeof(t_map))))
		exit(1);
	f->piece->y = ft_atoi(ft_strchr(line, ' '));
	f->piece->x = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	if (!(f->P_MAP = (char **)malloc(sizeof(char *) * (f->piece->y + 1))))
		exit(1);
	f->P_MAP[f->piece->y] = NULL;
	while (i < f->piece->y && get_next_line(STDIN_FILENO, &line))
	{
		f->P_MAP[i] = ft_strdup(line);
		free(line);
		i++;
	}
}

int		main(void)
{
	char		*line;
	t_filler	*filler;

	filler = (t_filler *)malloc(sizeof(t_filler));
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if ((ft_strstr(line, PLAYER_S) && line[0] == '$'))
			take_char(filler, line);
		else if (ft_strstr(line, "Plateau"))
			read_map(filler, line);
		else if (ft_strstr(line, "Piece "))
		{
			read_piece(filler, line);
			game(filler);
			free_arrays(filler);
		}
		free(line);
	}
	free(filler);
	return (0);
}
