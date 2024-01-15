/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:56:51 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/15 18:30:46 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_solong
{
	void	*ground;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*mlx;
	void	*mlx_win;
	void	*car;
	char	**map;
	char	**map_cpy;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		mapy;
	int		mapx;
	int		p_count;
	int		c_count;
	int		e_count;
	int		c_number;
	int		moves_number;
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
void		player_location(t_solong *solong);
void		ft_image_xpm(t_solong *map);
void		map_create(t_solong *creatmap);
void		map_cpy(char *map, t_solong *solong);
int			map_movement(int keycode, t_solong *movement);
void		keycode_1(t_solong *movement, int x, int y);
void		keycode_2(t_solong *movement, int x, int y);
void		keycode_0(t_solong *movement, int x, int y);
void		keycode_13(t_solong *movement, int x, int y);
void		ft_error(t_solong *solong);
void		ft_ferror(t_solong *solong);
int			ft_game_closed(t_solong *solong);
void		ft_zero(t_solong *solong);
void		texture_error(t_solong *solong);
void		texture_check(t_solong *solong);
void		map_create2(t_solong *solong, int x, int y);
void		map_name2(char *str);

#endif
