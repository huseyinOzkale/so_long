/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:32:07 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/15 18:15:14 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_closed(t_solong *solong)
{
	int	i;

	i = 0;
	ft_printf("game closed!");
	while (solong->map[i])
	{
		if (solong->map[i] != NULL)
			free(solong->map[i]);
		i++;
	}
	free(solong->map);
	free(solong);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	exit(1);
}

void	texture_error(t_solong *solong)
{
	int	i;

	ft_printf("texture error!");
	i = 0;
	free(solong);
	exit(1);
}

void	texture_check(t_solong *solong)
{
	int	fd;

	fd = open("textures/barrier.xpm", O_RDONLY);
	if (fd == -1)
		texture_error(solong);
	fd = open("textures/mcqueen.xpm", O_RDONLY);
	if (fd == -1)
		texture_error(solong);
	fd = open("textures/pistoncup.xpm", O_RDONLY);
	if (fd == -1)
		texture_error(solong);
	fd = open("textures/road.xpm", O_RDONLY);
	if (fd == -1)
		texture_error(solong);
	fd = open("textures/rr.xpm", O_RDONLY);
	if (fd == -1)
		texture_error(solong);
}
