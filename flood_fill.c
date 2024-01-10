/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:41:13 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/10 20:10:23 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	fill(t_solong *solong, int y, int x)
{
	char **map;

	map = solong->map_cpy;
	if (y < 0 || x < 0 || x >= solong->mapx || y >= solong->mapy)
			return ;
	if (map[y][x] == '8' || map[y][x] == '1')
			return ;
	map[y][x] = '8';
	fill(solong, y - 1, x);
	fill(solong, y + 1, x); 
	fill(solong, y, x - 1);
	fill(solong, y, x + 1);
	
}

void	flood_fill(t_solong *solong)
{
	fill(solong, solong->p_y, solong->p_x);

	int index = 0;
	while (solong->map_cpy[index])
	{
		printf("%s\n", solong->map_cpy[index]);
		index++;
	}
}