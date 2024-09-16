/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_creator2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:06:18 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/16 18:27:19 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	z_verif(t_data *data)
{
	write(1, "Z value in file is too big", 27);
	write(1, "(keep them between -100000 and 100000)", 39);
	freefree(data);
	delete_everything(data);
}

void	coord_creator(t_data *data, int n, int x, int y)
{
	int		m;
	char	**temp;

	temp = ft_split(data->array[x], ',');
	m = -1;
	data->tdp[n] = malloc(sizeof * data->tdp * 4);
	if (!data->tdp[n])
	{
		write(1, "malloc error", 13);
		delete_everything(data);
	}
	if (temp[1])
		data->tdp[n][3] = ft_atoi_base(temp[1], "0123456789ABCDEF");
	else
		data->tdp[n][3] = 0xFFFFFF;
	data->tdp[n][2] = ft_atoi(data->array[x]);
	data->tdp[n][1] = y;
	data->tdp[n][0] = x;
	while (temp[++m])
		free(temp[m]);
	free(temp);
	if (data->tdp[n][2] < -100000 || data->tdp[n][2] > 100000)
		z_verif(data);
}
