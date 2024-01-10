/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:08:14 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/10 17:04:38 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	map_len(t_solong *solong, char *map)
{
	int		len;
	int		fd;
	char	*map_reading;

	len = 0;
	fd = open(map, O_RDWR);
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
	int i;
	int len;
	int fd;
	char **map_str;

	i = 0;
	len = map_len(solong, map);
	fd = open(map, O_RDWR);
	if (fd < 0)
		return ;
	map_str = malloc(sizeof(char *) * (len + 1));
	solong->map_cpy=malloc(sizeof(char *) *(len + 1));
	if (!map_str)
		return ;
	while (i < len)
	{
		map_str[i++] = get_next_line(fd);
		solong->map_cpy=map_str;
	}
	map_str[i] = NULL;
	solong->map = map_str;
	close(fd);
}