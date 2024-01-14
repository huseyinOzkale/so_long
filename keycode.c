/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:52:43 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/14 18:06:59 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	keycode_2(t_solong *movement, int x, int y)
{
	if (movement->map[y][x + 1] == '0' || movement->map[y][x + 1] == 'C')
	{
		if (movement->map[y][x + 1] == 'C')
			movement->c_number++;
		movement->map[y][x] = '0';
		movement->map[y][x + 1] = 'P';
		movement->p_x++;
		movement->moves_number += 1;
		printf("moves_number : %d\n", movement->moves_number);
	}
	if (movement->map[y][x + 1] == 'E')
	{
		if (movement->c_count == movement->c_number)
		{
			ft_ferror(movement);
		}
	}
}

void	keycode_0(t_solong *movement, int x, int y)
{
	if (movement->map[y][x - 1] == '0' || movement->map[y][x - 1] == 'C')
	{
		if (movement->map[y][x - 1] == 'C')
			movement->c_number++;
		movement->map[y][x] = '0';
		movement->map[y][x - 1] = 'P';
		movement->p_x--;
		movement->moves_number += 1;
		printf("moves_number : %d\n", movement->moves_number);
	}
	if (movement->map[y][x - 1] == 'E')
	{
		if (movement->c_count == movement->c_number)
		{
			ft_ferror(movement);
		}
	}
}

void	keycode_13(t_solong *movement, int x, int y)
{
	if (movement->map[y - 1][x] == '0' || movement->map[y - 1][x] == 'C')
	{
		if (movement->map[y - 1][x] == 'C')
			movement->c_number++;
		movement->map[y][x] = '0';
		movement->map[y - 1][x] = 'P';
		movement->p_y--;
		movement->moves_number += 1;
		printf("moves_number : %d\n", movement->moves_number);
	}
	if (movement->map[y - 1][x] == 'E')
	{
		if (movement->c_count == movement->c_number)
		{
			ft_ferror(movement);
		}
	}
}

void	keycode_1(t_solong *movement, int x, int y)
{
	if (movement->map[y + 1][x] == '0' || movement->map[y + 1][x] == 'C')
	{
		if (movement->map[y + 1][x] == 'C')
			movement->c_number++;
		movement->map[y][x] = '0';
		movement->map[y + 1][x] = 'P';
		movement->p_y++;
		movement->moves_number += 1;
		printf("moves_number : %d\n", movement->moves_number);
	}
	if (movement->map[y + 1][x] == 'E')
	{
		if (movement->c_count == movement->c_number)
		{
			ft_ferror(movement);
		}
	}
}

int	map_movement(int keycode, t_solong *movement)
{
	int	x;
	int	y;

	x = movement->p_x;
	y = movement->p_y;
	if (keycode == 53)
		ft_game_closed(movement);
	if (keycode == 2 && movement->map[y][x + 1] != '1')
		keycode_2(movement, x, y);
	if (keycode == 0 && movement->map[y][x - 1] != '1')
		keycode_0(movement, x, y);
	if (keycode == 13 && movement->map[y - 1][x] != '1')
		keycode_13(movement, x, y);
	if (keycode == 1 && movement->map[y + 1][x] != '1')
		keycode_1(movement, x, y);
	map_create(movement);
	return (0);
}
