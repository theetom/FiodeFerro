/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:47:39 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/28 17:06:24 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(int keysim, t_count_data *count_values)
{
	int	n;

	n = -1;
	if (keysim == 0xff1b){
		mlx_destroy_window(count_values->t.mlx, count_values->t.mlx_win);
		mlx_destroy_display(count_values->t.mlx);	
		free(count_values->t.mlx);
		while(count_values->numbers[++n])
			free(count_values->numbers[++n]);
		free(count_values->numbers);
		exit(0);
	}
	return 0;
}
