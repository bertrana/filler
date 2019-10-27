/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.y                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:28:18 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/18 04:24:34 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"
# include  <string.h>

# define B_MAP board->map
# define P_MAP piece->map

# define X		0
# define Y		1
# define MAP_Y_X	f->B_MAP[res[Y]][res[X]]

# define PLAYER_S "yjohns"

# define FULL(ii, ji) (f->B_MAP[i + ii][j + ji])

# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))


typedef struct	s_map
{
	int			y;
	int			x;
	char		**map;
}				t_map;

typedef struct	s_filler
{
	char		enemy;
	char		player;
	t_map		*board;
	t_map		*piece;
	int			x; //result
	int 		y;

	short int	piece_x[20];
	short int	piece_y[20];
	int			piece_num;
	int			dst;
	int			index;
}				t_filler;


void			game(t_filler *f);

bool			manage_error(void);

void			player_ident(t_filler *f, char *line);
void			maps_create(t_filler *f, bool x);

bool			is_full(t_filler *f, int i, int j, char x);
int				count_dst(t_filler *f, int y, int x);
void			get_fig_coord(t_filler *f);

#endif
