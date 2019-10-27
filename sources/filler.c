/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:28:20 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/17 23:28:20 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	help_try_to_fit(t_filler *f, int res[], int i, int *mine)
{
	(res[X] < 0) && (res[X] = f->board->x - (res[X] * -1));
	(res[Y] < 0) && (res[Y] = f->board->y - (res[Y] * -1));
	(ft_tolower(MAP_Y_X) == f->player) && (*mine)++;
	if (ft_tolower(MAP_Y_X) == f->enemy
		|| *mine > 1 || MAP_Y_X == '\0'
		|| (i == f->piece_num - 1 && !*mine))
		return (0);
	return (1);
}

static int	try_to_fit(t_filler *f, int y, int x, int ind)
{
	int		i;
	int		res[2];
	int		mine;
	int		d;
	int		tmp;

	i = -1;
	mine = 0;
	d = INT32_MAX;
	while (++i < f->piece_num)
	{
		res[X] = x + f->piece_x[i] - f->piece_x[ind];
		res[Y] = y + f->piece_y[i] - f->piece_y[ind];
		if ((res[X] >= f->board->x) || (res[Y] >= f->board->y))
			return (0);
		if (!help_try_to_fit(f, res, i, &mine))
			return (0);
		tmp = count_dst(f, res[Y], res[X]);
		if (d >= tmp && (d = tmp) | 1)
			(d != INT32_MAX) && (f->index = ind);
	}
	return (d);
}

static void	best_solution(t_filler *f, int i, int j)
{
	int		d;
	int		index;

	d = 0;
	index = -1;
	while (++index < f->piece_num)
	{
		d = try_to_fit(f, i, j, index);
		if (d != 0 && f->dst > d)
		{
			(f->dst = d | 1)
			&& ((f->x = j - f->piece_x[f->index]) | 1)
			&& (f->y = i - f->piece_y[f->index]);
		}
	}
}

void		game(t_filler *f)
{
	int		i;
	int		j;

	i = 0;
	f->y = 0;
	f->x = 0;
	f->dst = INT32_MAX;
	get_fig_coord(f);
	while (f->B_MAP[i])
	{
		j = -1;
		while (f->B_MAP[i][++j])
		{
			if (ft_tolower(f->B_MAP[i][j]) == f->player
				&& !is_full(f, i, j, f->player))
				best_solution(f, i, j);
		}
		i++;
	}
	ft_putnbr(f->y);
	write(1, " ", 1);
	ft_putnbr(f->x);
	write(1, "\n", 1);
}