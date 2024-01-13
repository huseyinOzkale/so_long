/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:36:51 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/13 15:55:25 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_image_xpm(t_solong *map)
{
	int	a;
	int	b;

	map->coin = mlx_xpm_file_to_image(map->mlx, "rr.xpm", &a, &b);
	map->car = mlx_xpm_file_to_image(map->mlx, "mcqueen.xpm", &a, &b);
	map->wall = mlx_xpm_file_to_image(map->mlx, "barrier.xpm", &a, &b);
	map->ground = mlx_xpm_file_to_image(map->mlx, "road.xpm", &a, &b);
	map->exit = mlx_xpm_file_to_image(map->mlx, "pistoncup.xpm", &a, &b);
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
		}
	}
}

int	main(int ac, char **av)
{
	t_solong	*solong;

	if (ac != 2)
		return (0);
	solong = malloc(sizeof(t_solong));
	map_name(av[1]);
	map_reader(av[1], solong);
	map_checker(solong);
	object_check(solong);
	player_location(solong);
	flood_fill(solong);
	solong->x = 0;
	solong->y = 0;
	solong->mlx = mlx_init();
	ft_image_xpm(solong);
	map_create(solong);
	mlx_key_hook(solong->mlx_win, map_movement, solong);
	mlx_loop(solong->mlx);
}
// printf("%d", map_checker(a));

// int			index;
// index = 0;
// while (a->map[index])
// {
// 	printf("%s\n", a->map[index]);
// 	index++;
// }
// if (ft_is_rectangle(a) == 0)
// 	ft_error();

// int ft_key(int keycode, t_solong *a)
// {

// 	printf("%d\n",keycode);
// 	if(keycode==53)
// 	{
// 		mlx_destroy_window(a->mlx,a->mlx_win);
// 		exit(0);

// 	}
// 	else if(keycode==1)
// 	{
// 		mlx_clear_window(a->mlx,a->mlx_win);
// 		a->y++;
// 		mlx_put_image_to_window(a->mlx,a->mlx_win,a->car,a->x * 64, a->y * 64);
// 	}
// 	else if(keycode==2)
// 	{
// 		mlx_clear_window(a->mlx,a->mlx_win);
// 		a->x++;
// 		mlx_put_image_to_window(a->mlx,a->mlx_win,a->car,a->x *64,a->y*64);
// 	}
// 	else if(keycode==0)
// 	{
// 		mlx_clear_window(a->mlx,a->mlx_win);
// 		a->x--;
// 		mlx_put_image_to_window(a->mlx,a->mlx_win,a->car,a->x * 64 ,a->y * 64);
// 	}
// 	else if(keycode==13)
// 	{
// 		mlx_clear_window(a->mlx,a->mlx_win);
// 		a->y--;
// 		mlx_put_image_to_window(a->mlx,a->mlx_win,a->car,a->x * 64,a->y * 64);
// 	}
// 	map_create(a);
// 	return (0);
// }