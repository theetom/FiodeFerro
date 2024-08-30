/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:59:05 by toferrei          #+#    #+#             */
/*   Updated: 2024/08/30 15:34:12 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(int keysim, t_data *data)
{
	int n;

	n = -1;
	if (keysim == 0xff1b)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);	
		free(data->mlx);
		while(data->tdp[++n])
			free(data->tdp[++n]);
		free(data->tdp);
		exit(0);
	}
	return 0;
}
