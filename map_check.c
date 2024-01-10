/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:36:51 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/10 19:53:13 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "solong.h"

// void ft_xpm(t_solong *map)
// {
// 	int a;
// 	int b;

// 	map->coin=mlx_xpm_file_to_image(map->mlx,"rr.xpm",&a,&b);
// 	map->car=mlx_xpm_file_to_image(map->mlx,"mcqueen.xpm",&a,&b);
// 	map->wall=mlx_xpm_file_to_image(map->mlx,"barrier.xpm",&a,&b);
// 	map->ground=mlx_file_to_image(map->mlx,"road.xpm",&a,&b);
// 	map->mlx_win=mlx_new_window(map->mlx,1920,1080,"SOLONG");

// }

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

void	palyer_location(t_solong *solong)
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

	 //int			index;
	if (ac != 2)
		return (0);
	solong = malloc(sizeof(t_solong));

	map_name(av[1]);
	map_reader(av[1], solong);
	map_checker(solong);
	object_check(solong);
	palyer_location(solong);
	flood_fill(solong);
}
// printf("%d", map_checker(a));

// index = 0;
// while (a->map[index])
// {
// 	printf("%s\n", a->map[index]);
// 	index++;
// }
// if (ft_is_rectangle(a) == 0)
// 	ft_error();

// int c;
// int b;
// a.x = 0;
// a.y = 0;
// a.mlx = mlx_init();
// a.mlx_win = mlx_new_window(a.mlx, 1920, 1080, "solong");
// a.car = mlx_xpm_file_to_image(a.mlx,"mcqueen.xpm", &c, &b);
// mlx_put_image_to_window(a.mlx,a.mlx_win,a.car,a.x * 64, a.y * 64);
// ft_xpm(&a);
// mlx_key_hook(a.mlx_win,ft_key,&a);
// mlx_loop(a.mlx);
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
// 	return (0);
// }