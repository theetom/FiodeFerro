/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:57:11 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/03 15:19:08 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void points_shower(t_data *data)
{
	int n = -1;
	while (data->tdp[++n])
	{
		printf("point #%d	x:%d	y:%d	z:%d\n", n, data->tdp[n][0], data->tdp[n][1], data->tdp[n][2]);
	}
}
/* void verifs()
{
	
} */

int	main(int argc, char *argv[])
{
	t_data	data;

	data.img_h = 1080;
	data.img_w = 1920;
	data.tdp = NULL;
	if (argc != 2)
		return (0);
	points_creator(argv[1], &data);
	points_shower(&data);
	struct_init(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "My Fdf!");
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	two_to_three(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 2, KeyPressMask, close_window, &data);
	mlx_loop(data.mlx);
}
