/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:50:54 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/06 15:18:17 by toferrei         ###   ########.fr       */
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
	printf("x_max:%f	x_min:%f	y_max:%f	y_min:%f\n", data->x_max, data->x_min, data->y_max, data->y_min);
	printf("x_max:%f	x_min:%f	y_max:%f	y_min:%f\n", data->x_max*data->scale, data->x_min*data->scale, data->y_max*data->scale, data->y_min*data->scale);
	printf("scale:%f\n", data->scale);
	data->position_w = (data->img_w / 2) - (((data->x_max - data->x_min) / 2) * data->scale);
	data->position_h = (data->img_h / 2) - (((data->y_max - data->y_min) / 2) * data->scale); //(data->img_h / 2) - (((data->y_max - data->y_min) * data->scale) / 2);
	printf("posh:%f\n", data->position_h);
	printf("posw:%f\n", data->position_w);
	printf("x_max:%f	x_min:%f\n", data->x_max * data->scale + data->position_w, data->x_min * data->scale + data->position_w);
	printf("y_max:%f	y_min:%f\n", data->y_max * data->scale + data->position_h, data->y_min * data->scale + data->position_h);
}
