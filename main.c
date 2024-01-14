/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:41:49 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/14 18:28:49 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_zero(t_solong *solong)
{
	solong->c_count = 0;
	solong->c_number = 0;
	solong->coin = 0;
	solong->p_x = 0;
	solong->p_y = 0;
	solong->mapy = 0;
	solong->mapx = 0;
	solong->p_count = 0;
	solong->e_count = 0;
	solong->moves_number = 0;
}

int	main(int ac, char **av)
{
	t_solong	*solong;

	if (ac != 2)
		return (0);
	solong = malloc(sizeof(t_solong));
	if (!solong)
		return (0);
	ft_zero(solong);
	texture_check(solong);
	map_name(av[1]);
	map_reader(av[1], solong);
	map_checker(solong);
	object_check(solong);
	player_location(solong);
	flood_fill(solong);
	solong->mlx = mlx_init();
	ft_image_xpm(solong);
	map_create(solong);
	mlx_key_hook(solong->mlx_win, map_movement, solong);
	mlx_hook(solong->mlx_win, 17, 0, ft_game_closed, solong);
	mlx_loop(solong->mlx);
}
