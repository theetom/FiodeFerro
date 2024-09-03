/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:50:54 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/03 17:03:31 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	two_d_cos(t_data *data, int n)
{
	return ((data->tdp[n][0]) * cos(120) + (data->tdp[n][1]) * cos(120 + 2) + (data->tdp[n][2]) * cos(120 - 2));
}

static double	two_d_sin(t_data *data, int n)
{
	return ((data->tdp[n][0]) * sin(120) + (data->tdp[n][1])
			* sin(120 + 2) + (data->tdp[n][2]) * sin(120 - 2));
}

void	struct_init(t_data *data)
{
	int		n;

	n = 0;
	data->x_min = two_d_cos(data, n);
	data->y_min = two_d_sin(data, n);
	data->x_max = two_d_cos(data, n);
	data->y_max = two_d_sin(data, n);
	while (data->tdp[n + 1])
	{
		n++;
		if (data->x_max < two_d_cos(data, n))
			data->x_max = two_d_cos(data, n);
		if (data->y_max < two_d_sin(data, n))
			data->y_max = two_d_sin(data, n);
		if (data->x_min > two_d_cos(data, n))
			data->x_min = two_d_cos(data, n);
		if (data->y_min > two_d_sin(data, n))
			data->y_min = two_d_sin(data, n);
	}
	data->scale = 40 / (((data->y_max - data->y_min) * 100) / data->img_w);
	data->position_w = data->img_w / 2 - ((((data->x_max + data->x_min)
					* data->scale) / 2));
	data->position_h = data->img_h / 2 - ((((data->y_max + data->y_min)
					* data->scale) / 2));
}
