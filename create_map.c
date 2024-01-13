/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:44:04 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/13 15:58:13 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_create(t_solong *creatmap)
{
	int	x;
	int	y;

	y = -1;
	while (creatmap->map[++y])
	{
		x = -1;
		while (creatmap->map[y][++x])
		{
			if (creatmap->map[y][x] == '0')
				mlx_put_image_to_window(creatmap->mlx, creatmap->mlx_win,
					creatmap->ground, x * 64, y * 64);
			else if (creatmap->map[y][x] == '1')
				mlx_put_image_to_window(creatmap->mlx, creatmap->mlx_win,
					creatmap->wall, x * 64, y * 64);
			else if (creatmap->map[y][x] == 'P')
				mlx_put_image_to_window(creatmap->mlx, creatmap->mlx_win,
					creatmap->car, x * 64, y * 64);
			else if (creatmap->map[y][x] == 'C')
				mlx_put_image_to_window(creatmap->mlx, creatmap->mlx_win,
					creatmap->coin, x * 64, y * 64);
			else if (creatmap->map[y][x] == 'E')
				mlx_put_image_to_window(creatmap->mlx, creatmap->mlx_win,
					creatmap->exit, x * 64, y * 64);
		}
	}
}
