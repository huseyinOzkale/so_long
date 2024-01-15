/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:41:13 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/15 18:05:34 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_solong *solong, int y, int x)
{
	char	**map;

	map = solong->map_cpy;
	if (y < 0 || x < 0 || x >= solong->mapx || y >= solong->mapy)
		return ;
	if (map[y][x] == 'H' || map[y][x] == '1')
		return ;
	map[y][x] = 'H';
	fill(solong, y - 1, x);
	fill(solong, y + 1, x);
	fill(solong, y, x - 1);
	fill(solong, y, x + 1);
}

void	flood_fill(t_solong *solong)
{
	int	x;
	int	y;

	fill(solong, solong->p_y, solong->p_x);
	y = -1;
	while (solong->map_cpy[++y])
	{
		x = -1;
		while (solong->map_cpy[y][++x])
		{
			if (ft_strchr("EC", solong->map_cpy[y][x]))
				ft_error(solong);
		}
	}
	x = -1;
	while (solong->map_cpy[++x])
	{
		free(solong->map_cpy[x]);
	}
	free(solong->map_cpy);
}
