/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:28:18 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/18 04:24:34 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "stdio.h"
# include "../libft/libft.h"


typedef struct	s_map
{
	int			h_map;
	int			w_map;
	int			**num_map;
}				t_map;

typedef struct	s_fil
{
	char		enemy;
	char		player;
	t_map		*board;
	t_map		*piece;
	int			x;
	int 		y;
}				t_fil;

#endif