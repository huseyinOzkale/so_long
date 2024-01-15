/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:44:04 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/15 16:57:21 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_create(t_solong *creatmap)
{
	int	x;
	int	y;

	if (creatmap->map[creatmap->e_y][creatmap->e_x] == '0')
		creatmap->map[creatmap->e_y][creatmap->e_x] = 'E';
	y = -1;
	while (creatmap->map[++y])
	{
		x = -1;
		while (creatmap->map[y][++x])
		{
			if (creatmap->map[y][x] == '0')
				map_create2(creatmap, x, y);
			else if (creatmap->map[y][x] == '1')
				map_create2(creatmap, x, y);
			else if (creatmap->map[y][x] == 'P')
				map_create2(creatmap, x, y);
			else if (creatmap->map[y][x] == 'C')
				map_create2(creatmap, x, y);
			else if (creatmap->map[y][x] == 'E')
				map_create2(creatmap, x, y);
		}
	}
}

void	map_create2(t_solong *solong, int x, int y)
{
	if (solong->map[y][x] == '0')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->ground, x * 64, y * 64);
	else if (solong->map[y][x] == '1')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->wall, x * 64, y * 64);
	else if (solong->map[y][x] == 'P')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win, solong->car,
			x * 64, y * 64);
	else if (solong->map[y][x] == 'C')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->coin, x * 64, y * 64);
	else if (solong->map[y][x] == 'E')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->exit, x * 64, y * 64);
}
