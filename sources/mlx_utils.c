/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:57:56 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/13 15:40:03 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	two_d_cos(int position, int scale, t_data *data, int n)
{
	return (scale * ((data->tdp[n][0]) * cos(data->anglex) + (data->tdp[n][1])
			* cos(data->angley + 2) + (data->tdp[n][2]) * cos(data->anglez - 2)) + position);
}

double	two_d_sin(int position, int scale, t_data *data, int n)
{
	return (scale * ((data->tdp[n][0]) * sin(data->anglex) + (data->tdp[n][1])
			* sin(data->angley + 2) + (data->tdp[n][2]) * sin(data->anglez - 2)) + position);
}
