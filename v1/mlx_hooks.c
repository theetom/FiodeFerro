/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:59:05 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/06 12:02:22 by toferrei         ###   ########.fr       */
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


int	close_window(int keysim, t_data *data)
{
	
	if (keysim == ESC)
		delete_everything(data);
	return (0);
}
