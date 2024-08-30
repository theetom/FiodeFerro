/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:39:41 by toferrei          #+#    #+#             */
/*   Updated: 2024/08/30 15:38:39 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void struct_init(t_count_data *count_values, int **numbers)
{
	double x_min;
	double y_min;
	double x_max;
	double y_max;
	int n;

	n = 0;
	x_min = ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2));
	y_min = ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2));
	x_max = ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2));
	y_max = ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2));
	while (numbers[n + 1])
	{	
		n++;
		if (x_max < ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2)))
			x_max = ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2));
		if (y_max < ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2)))
			y_max = ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2));
		if (x_min > ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2)))
			x_min = ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2));
		if (y_min > ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2)))
			y_min = ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2));
	}
	count_values->scale = 70 / (((y_max - y_min) * 100) / 1080);
	count_values->position_w = count_values->t.img_w / 2 - ((((x_max + x_min) * count_values->scale) / 2));
	count_values->position_h = count_values->t.img_h / 2 - ((((y_max + y_min) * count_values->scale) / 2));
}

int	main(int argc, char *argv[])
{
	t_count_data	count_values;
	
	count_values.numbers = NULL;
	if(argc != 2)
		return (0);
	points_creator(argv[1], &count_values.numbers, &count_values);
	count_values.t.mlx = mlx_init();
	count_values.t.img_h = 1080;
	count_values.t.img_w = 1920;
	struct_init(&count_values, count_values.numbers);
	count_values.t.mlx_win = mlx_new_window(count_values.t.mlx, count_values.t.img_w, count_values.t.img_h, "MyFdf");
	count_values.img.img = mlx_new_image(count_values.t.mlx, count_values.t.img_w, count_values.t.img_h);
	count_values.img.addr = mlx_get_data_addr(count_values.img.img, &count_values.img.bits_per_pixel, &count_values.img.line_length, &count_values.img.endian);
	two_to_three(count_values.numbers, &count_values);
	mlx_put_image_to_window(count_values.t.mlx, count_values.t.mlx_win, count_values.img.img, 0, 0);
	mlx_hook(count_values.t.mlx_win, 2, KeyPressMask, close_window, &count_values);
	mlx_loop(count_values.t.mlx);
	return (0);
}
