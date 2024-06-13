/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:39:41 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/13 18:52:02 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char *argv[])
{
	char	*new_line;
	char	**array;
	int		fd;
	int		n = 0;
	char	**numbers;
	int		x = 0;
	int		y = 0;
	int		count = 0;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		xx;
	int		yy;
	
	if(argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((new_line = get_next_line(fd)))
	{
		array = ft_split(new_line, ' ');
		while(array[x])
		{
			count++;
			x++;
		}
		x = 0;
		free(new_line);
	}
	numbers = malloc(sizeof * numbers * count + 1);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while ((new_line = get_next_line(fd)))
	{
		array = ft_split(new_line, ' ');
		while(array[x])
		{
			numbers[n] = malloc(sizeof(int) * 3);
			numbers[n][2] = ft_atoi(array[x]);
			numbers[n][1] = y;
			numbers[n][0] = x;
			// printf("x:%d y:%d z:%d\n", numbers[n][0], numbers[n][1], numbers[n][2]);
			x++;
			n++;
		}
		y++;
		x = 0;
		free(new_line);
	}
	numbers[n] = "\0";
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "MyFdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	n = 0;
	while(numbers[n])
	{
		// printf("x:%d y:%d z:%d\n", numbers[n][0], numbers[n][1], numbers[n][2]);
		xx = (1920/2 + 5 * ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2)));
		yy = (1080/2 + 5 * ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2)));
		if (xx > 0 && xx < 1920 && yy < 1080 && 0 < yy)
			my_mlx_pixel_put(&img, xx, yy, 0x00FF0000);
		n++;
	}
	// printf("ola");
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
