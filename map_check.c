/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:36:51 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/15 16:57:39 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_xpm(t_solong *map)
{
	int	a;
	int	b;

	map->coin = mlx_xpm_file_to_image(map->mlx, "textures/rr.xpm", &a, &b);
	map->car = mlx_xpm_file_to_image(map->mlx, "textures/mcqueen.xpm", &a, &b);
	map->wall = mlx_xpm_file_to_image(map->mlx, "textures/barrier.xpm", &a, &b);
	map->ground = mlx_xpm_file_to_image(map->mlx, "textures/road.xpm", &a, &b);
	map->exit = mlx_xpm_file_to_image(map->mlx,
			"textures/pistoncup.xpm", &a, &b);
	if (!map->coin || !map->car || !map->wall || !map->ground || !map->exit)
		ft_print_error(map);
	map->mlx_win = mlx_new_window(map->mlx, map->mapx * 64, map->mapy * 64,
			"SOLONG");
}

int	map_checker(t_solong *mapcheck)
{
	char	**map;
	int		x;
	int		y;

	y = -1;
	map = mapcheck->map;
	if (!mapcheck->map[0])
		ft_print_error(mapcheck);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if ((y == 0 || y == mapcheck->mapy - 1) && map[y][x] != '1')
				ft_print_error(mapcheck);
			else if ((x == 0 || x == mapcheck->mapx - 1) && map[y][x] != '1')
				ft_print_error(mapcheck);
			else if (!ft_strchr("10ECP", mapcheck->map[y][x]))
				ft_print_error(mapcheck);
		}
		if (mapcheck->mapx != x)
			ft_print_error(mapcheck);
	}
	return (1);
}

void	player_location(t_solong *solong)
{
	int	x;
	int	y;

	y = -1;
	while (solong->map[++y])
	{
		x = -1;
		while (solong->map[y][++x])
		{
			if (solong->map[y][x] == 'P')
			{
				solong->p_x = x;
				solong->p_y = y;
			}
			else if (solong->map[y][x] == 'E')
			{
				solong->e_x = x;
				solong->e_y = y;
			}
		}
	}
}
