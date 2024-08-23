/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:10:42 by toferrei          #+#    #+#             */
/*   Updated: 2024/08/23 15:20:38 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int find_colour(double x, double x_min, double x_max)
{
	double percent;
	int r = 0;
	int b = 0;
	int g = 0;
	percent = ((x - x_min) / (x_max - x_min));
	if (percent <= 0.333333 || percent >= 0.666666)
	{
		if (percent <= 0.166666 || percent >= 0.833333)
		{
			{
				r = 255;
			}
		}
		else
		{	
			if (percent <= 0.333333)
				r = (-6 * percent + 0.166666) * 255;
			else
				r = (6 * percent - 0.666666) * 255;
		}
		
	}
	//printf("x:%f x_min:%f x_max:%f percent:%f\n", x, x_min, x_max, percent);
	
	return (create_trgb(0, r, g, b));
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x_min = 200;
	int y_min = 200;
	int x_max = 600;
	int y_max = 600;
	int x;
	int y;
	x = x_min;
	y = y_min;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Tomaz's Fdf");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	while(y <= y_max)
	{
		while(x <= x_max)
		{
			my_mlx_pixel_put(&img, x, y, find_colour(x, x_min, x_max));
			x++;
		}
		x = x_min;
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}