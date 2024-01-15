/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:25:36 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/15 17:12:17 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i <= 3)
	{
		ft_printf("MAP NAME ERROR!");
		exit(1);
	}
	if (str[i] != 'r' || str[i - 1] != 'e'
		|| str[i - 2] != 'b' || str[i - 3] != '.')
	{
		ft_printf("MAP NAME ERROR!");
		exit(1);
	}
	if (str[i - 4] == '.' || str[i - 4] == '/')
	{
		if (str[i - 5] && str[i - 4] != '/')
			return ;
		ft_printf("MAP NAME ERROR!");
		exit(1);
	}
}

void	map_name2(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("map not found!");
		exit(1);
	}
}
