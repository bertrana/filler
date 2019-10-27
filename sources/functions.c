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

void	get_fig_coord(t_filler *f)
{
	int		i;
	int		j;

	i = 0;
	f->piece_num = 0;
	while (f->P_MAP[i])
	{
		j = 0;
		while (f->P_MAP[i][j])
		{
			if (f->P_MAP[i][j] == '*')
			{
				f->piece_y[f->piece_num] = i;
				f->piece_x[f->piece_num++] = j;
			}
			j++;
		}
		i++;
	}
}

bool is_full(t_filler *f, int i, int j)
{
	return (!(i + 1 < f->board->y && j + 1 < f->board->x
			 && i >= 0 && j >= 0));
}

int		count_dst(t_filler *f, int y, int x)
{
	int		i;
	int		j;
	int		m;
	int		man;

	i = 0;
	j = 0;
	m = INT32_MAX;
	while (f->B_MAP[i])
	{
		j = -1;
		while (f->B_MAP[i][++j])
			if (ft_tolower(f->B_MAP[i][j]) == f->enemy
				&& !is_full(f, i, j))
			{
				man = ABS(x - j) + ABS(y - i);
				m = (m > man) ? man : m;
			}
		i++;
	}
	return (m);
}
