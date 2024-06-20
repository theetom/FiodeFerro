/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:47:39 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/20 13:27:18 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(int keysim, t_data *t)
{
	if (keysim == 0xff1b){
		mlx_destroy_window(t->mlx, t->mlx_win);
		mlx_destroy_display(t->mlx);	
		free(t->mlx);
		exit(0);
	}
	return 0;
}
