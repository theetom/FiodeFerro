/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:57:11 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/10 18:40:52 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_hooks(t_data *data)
{	
	mlx_key_hook(data->mlx_win, keys, data);
	// mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, keys, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, delete_everything, data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.angle = 120;
	data.anglec = 120;
	data.angles = 2;

	data.img_h = 1080;
	data.img_w = 1920;
	data.tdp = NULL;
	if (argc != 2)
		return (0);
	data.zx = 1;
	points_creator(argv[1], &data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.img_w, data.img_h, "My Fdf!");
	ft_hooks(&data);
	struct_init(&data);
	data.img = mlx_new_image(data.mlx, data.img_w, data.img_h);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	two_to_three(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
}
