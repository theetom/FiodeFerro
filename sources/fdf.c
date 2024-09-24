/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:57:11 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/24 11:28:08 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init(t_data *data)
{
	data->anglex = 120;
	data->angley = 120;
	data->anglez = 120;
	data->img_h = 1080;
	data->img_w = 1920;
	data->zx = 1;
	data->tdp = NULL;
}

void	ft_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 02, (1L << 0), keypress, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, delete_everything, data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init(&data);
	first_verifs(argc, argv[1]);
	points_creator(argv[1], &data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.img_w, data.img_h, "My Fdf!");
	ft_hooks(&data);
	struct_init(&data);
	data.img = mlx_new_image(data.mlx, data.img_w, data.img_h);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	z_verif(&data);
	two_to_three(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
}
