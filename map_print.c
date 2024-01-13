/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:08:14 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/13 15:57:52 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	map_len(t_solong *solong, char *map)
{
	int		len;
	int		fd;
	char	*map_reading;

	len = 0;
	fd = open(map, O_RDONLY);
	map_reading = get_next_line(fd);
	solong->mapx = ft_strlen(map_reading);
	while (map_reading)
	{
		len++;
		free(map_reading);
		map_reading = get_next_line(fd);
	}
	solong->mapy = len;
	close(fd);
	return (len);
}

void	map_reader(char *map, t_solong *solong)
{
	int	i;
	int	len;
	int	fd;

	i = 0;
	len = map_len(solong, map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	solong->map = malloc(sizeof(char *) * (len + 1));
	if (!solong->map)
		return ;
	while (i < len)
	{
		solong->map[i] = get_next_line(fd);
		i++;
	}
	solong->map[i] = NULL;
	close(fd);
	map_cpy(map, solong);
}

void	map_cpy(char *map, t_solong *solong)
{
	int	i;
	int	len;
	int	fd;

	i = 0;
	len = map_len(solong, map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	solong->map_cpy = malloc(sizeof(char *) * (len + 1));
	if (!solong->map_cpy)
		return ;
	while (i < len)
	{
		solong->map_cpy[i] = get_next_line(fd);
		i++;
	}
	solong->map_cpy[i] = NULL;
	close(fd);
}
