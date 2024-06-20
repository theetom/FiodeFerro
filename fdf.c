/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:39:41 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/20 16:05:01 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	int		**numbers;
	t_data	t; 
	t_data	img;
	
	if(argc != 2)
		return (0);
	t.mlx = mlx_init();
	t.img_h = 1080;
	t.img_w = 1920;
	points_creator(argv[1], numbers);
	two_to_three(numbers);
	t.mlx_win = mlx_new_window(t.mlx, t.img_w, t.img_h, "MyFdf");
	img.img = mlx_new_image(t.mlx, t.img_w, t.img_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(t.mlx, t.mlx_win, img.img, 0, 0);
	mlx_hook(t.mlx_win, 2, KeyPressMask, &close_window, &t);
	mlx_loop(t.mlx);
	return (0);
}
