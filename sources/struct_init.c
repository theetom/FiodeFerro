/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:50:54 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/10 15:39:13 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double scale(t_data *data)
{
	double width;
	double height;
	
	width = data->x_max - data->x_min;
	height = data->y_max - data->y_min;
	if(height / data->img_h * 100 > width / data->img_h * 100)
		return (75 / (((data->y_max - data->y_min)
				* 100) / (data->img_h)));
	else
		return (75 / (((data->x_max - data->x_min)
				* 100) / (data->img_w)));
}

void	struct_init(t_data *data)
{
	int		n;

	n = 0;
	data->x_min = two_d_cos(0, 1, data, n);
	data->y_min = two_d_sin(0, 1, data, n);
	data->x_max = two_d_cos(0, 1, data, n);
	data->y_max = two_d_sin(0, 1, data, n);
	while (n < data->count - 1)
	{
		n++;
		if (data->x_max < two_d_cos(0, 1, data, n))
			data->x_max = two_d_cos(0, 1, data, n);
		if (data->y_max < two_d_sin(0, 1, data, n))
			data->y_max = two_d_sin(0, 1, data, n);
		if (data->x_min > two_d_cos(0, 1, data, n))
			data->x_min = two_d_cos(0, 1, data, n);
		if (data->y_min > two_d_sin(0, 1, data, n))
			data->y_min = two_d_sin(0, 1, data, n);
	}
	data->scale = scale(data);
	if (data->scale < 1)
		data->scale = 1;
	data->position_w = (data->img_w - ((data->x_max - data->x_min) * data->scale)) / 2 - (data->x_min * data->scale);
	data->position_h = (data->img_h - ((data->y_max - data->y_min) * data->scale)) / 2 - (data->y_min * data->scale);
}
