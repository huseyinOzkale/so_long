/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozkale <huozkale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:25:36 by huozkale          #+#    #+#             */
/*   Updated: 2024/01/10 18:25:37 by huozkale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_name(char *str)
{
	int i = 0;
	i = ft_strlen(str) - 1;
	if (i <= 3)
	{
		printf("MAP NAME ERROR!");
		exit(1);
	}
	else if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i
		- 3] != '.')
	{
		printf("MAP NAME ERROR!");
		exit(1);
	}
}