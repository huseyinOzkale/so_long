/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:37:10 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/10 20:01:37 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
typedef struct s_solong
{
	void	*ground;
	void	*wall;
	void	*coin;
	void	*mlx;
	void	*mlx_win;
	void	*car;
	char	**map;
	char	**map_cpy;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		mapy;
	int		mapx;
	int		p_count;
	int		c_count;
	int		e_count;
}			t_solong;

int			map_checker(t_solong *mapcheck);
int			map_len(t_solong *solong, char *map);
void		map_reader(char *map, t_solong *solong);
void		object_count(t_solong *solong);
void		ft_print_error(t_solong *solong);
void		object_check(t_solong *solong);
void		map_name(char *str);
void		fill(t_solong *solong, int y, int x);
void		flood_fill(t_solong *solong);

#endif