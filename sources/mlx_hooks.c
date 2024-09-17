/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:59:05 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/17 16:23:06 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	delete_everything(t_data *data)
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
	free(data->z);
	exit(0);
}

static void	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	two_to_three(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

static void	z_decrement(int k, t_data *data)
{
	int	n;

	n = 0;
	if (k == R && data->zx > 0.1)
		data->zx -= 0.1;
	if (k == F && data->zx < 0.9)
		data->zx += 0.1;
	while (n < data->count)
	{
		data->tdp[n][2] = data->z[n] * data->zx;
		n++;
	}
}

static void	position(int k, t_data *data)
{
	if (k == W)
		data->position_h -= 50;
	if (k == A)
		data->position_w -= 50;
	if (k == S)
		data->position_h += 50;
	if (k == D)
		data->position_w += 50;
}

int	keypress(int k, t_data *data)
{
	if (k == ESC)
		delete_everything(data);
	if (k == W || k == A || k == S || k == D)
		position(k, data);
	if (k == PLUS)
		data->scale *= 1.5;
	if (k == MINUS)
		data->scale /= 1.5;
	if (k == R || k == F)
		z_decrement(k, data);
	if (k == Z || k == X || k == C || k == V || k == B || k == N)
		rotate(k, data);
	render (data);
	return (0);
}
