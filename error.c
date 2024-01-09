/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:08:03 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/09 19:21:53 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_print_error(char *str, t_solong *solong)
{
	int	i;

	i = 0;
	printf("%s", str);
	while (solong->map[i])
	{
		if (solong->map[i] != NULL)
			free(solong->map[i]);
		i++;
	}
	free(solong->map);
	exit(1);
}

void	object_count(t_solong *solong)
{
	int	x;
	int	y;

	solong->c_count = 0;
	solong->p_count = 0;
	solong->e_count = 0;
	y = -1;
	while (solong->map[++y])
	{
		x = -1;
		while (solong->map[y][++x])
		{
			if (solong->map[y][x] == 'P')
				solong->p_count += 1;
			else if (solong->map[y][x] == 'C')
				solong->c_count += 1;
			else if (solong->map[y][x] == 'E')
				solong->e_count += 1;
		}
	}
}

void	object_check(t_solong *solong)
{
	object_count(solong);
	if (solong->p_count != 1)
		ft_print_error("hatalı player", solong);
	else if (solong->e_count != 1)
		ft_print_error("hatalı exit", solong);
	else if (solong->c_count != 1)
		ft_print_error("hatalı coin", solong);
}