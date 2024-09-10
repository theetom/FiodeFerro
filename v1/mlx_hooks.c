/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:59:05 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/10 18:44:39 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int delete_everything(t_data *data)
{
	int	n;

	n = 0;
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	while (n < data->count)
		free(data->tdp[n++]);
	free(data->tdp);
	exit(0);
}	

void render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	two_to_three(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void z_decrement(int keysim, t_data *data)
{
	int n;

	n = 0;
	if (keysim == R && data->zx > 1)
		data->zx -= 1;
	if (keysim == F)
		data->zx += 1;
	while (n < data->count)
	{
		data->tdp[n][2] = data->z[n] / data->zx;
		n++;
	}
}

int	keys(int keysim, t_data *data)
{
	
	if (keysim == ESC)
		delete_everything(data);
	if (keysim == W)
		data->position_h -= 50;
	if (keysim == A)
		data->position_w -= 50;
	if (keysim == S)
		data->position_h += 50;
	if (keysim == D)
		data->position_w += 50;
	if (keysim == PLUS)
		data->scale *= 1.5;
	if (keysim == MINUS)
		data->scale /= 1.5;
	if (keysim == R || keysim == F)
		z_decrement(keysim, data);
	if (keysim == Z)
		data->anglec += 0.1;
	if (keysim == X)
		data->anglec -= 0.1;
	if (keysim == C)
		data->angles += 0.1;
	if (keysim == V)
		data->angles -= 0.1;
	if (keysim == B)
		data->angle += 0.1;
	if (keysim == N)
		data->angle -= 0.1;
	render (data);
	return (0);
	
}


