/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:39:41 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/14 18:46:32 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/X.h>
//library from keys
#include <X11/keysym.h>

	typedef struct t
	{
		void	*mlx;
		void	*mlx_win;
	} t_t;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(int keysim, t_t *t)
{
	if (keysim == 0xff1b){
		mlx_destroy_window(t->mlx, t->mlx_win);
		mlx_destroy_display(t->mlx);	
		free(t->mlx);
		exit(0);
	}
	return 0;
}

int	main(int argc, char *argv[])
{
	char	*new_line;
	char	**array;
	int		fd;
	int		n = 0;
	int	**numbers;
	int		x = 0;
	int		y = 0;
	int		count_lines = 0;
	int		count_in_line = 0;
	int		count;
	t_t t; 
	t_data	img;
	float		xx;
	float		xx1;
	float		yy;
	float		yy1;
	int		scale;
	float		a;
	float		b;
	float		c;
	
	if(argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((new_line = get_next_line(fd)))
	{
		count_lines++;
		if (count_in_line == 0)
		{
			array = ft_split(new_line, ' ');
			while(array[x])
			{
				count_in_line++;
				x++;
			}
		x = 0;
		free(new_line);
		}
	}
	count = (count_lines * count_in_line) + count_in_line + 1;
	numbers = malloc(sizeof * numbers * count);
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
	while (n < count)
		numbers[n++] = NULL;
	t.mlx = mlx_init();
	t.mlx_win = mlx_new_window(t.mlx, 1920, 1080, "MyFdf");
	img.img = mlx_new_image(t.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	n = 0;
	int z;
	while(numbers[n])
	{
		scale = 40;
		printf("%i \n", n);
		
		xx = (1920/2 + scale * ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2)));
		yy = (1080/2 + scale * ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2)));
		printf("x:%d	y:%d	z:%d	xx:%f	yy:%f\n", numbers[n][0], numbers[n][1], numbers[n][2], xx, yy);
		if (xx > 0 && xx < 1920 && yy < 1080 && 0 < yy)
			my_mlx_pixel_put(&img, xx, yy, 0x00FF0000);
		if (numbers[n + 1])
		{
			xx1 = (1920/2 + scale * ((numbers[n + 1][0]) * cos(120) + (numbers[n + 1][1]) * cos(120 + 2) + (numbers[n + 1][2]) * cos(120 - 2)));
			yy1 = (1080/2 + scale * ((numbers[n + 1][0]) * sin(120) + (numbers[n + 1][1]) * sin(120 + 2) + (numbers[n + 1][2]) * sin(120 - 2)));
			// printf("xx1:%f	yy1:%f\n", xx1, yy1);
			x = xx;
			while (x < xx1)
			{
				a = ((yy1 - yy) / (xx1 - xx));
				b = yy - (a * xx);
				c = (a * x + b);
				// printf("xxxxxx:	a:%f	b:%f	c:%f\n", a ,b ,c);
				if (x > 0 && x < 1920 && c < 1080 && 0 < c)
					my_mlx_pixel_put(&img, x, c, 0x00FFFFFF);
				x++;
			}
		}
		if (numbers[n - count_in_line] && n >= count_in_line)
		{
			xx1 = (1920/2 + scale * ((numbers[n - count_in_line][0]) * cos(120) + (numbers[n - count_in_line][1]) * cos(120 + 2) + (numbers[n - count_in_line][2]) * cos(120 - 2)));
			yy1 = (1080/2 + scale * ((numbers[n - count_in_line][0]) * sin(120) + (numbers[n - count_in_line][1]) * sin(120 + 2) + (numbers[n - count_in_line][2]) * sin(120 - 2)));
			printf("xx1:%f	yy1:%f\n", xx1, yy1);
			x = xx;
			while (x < xx1)
			{ 
				a = ((yy1 - yy) / (xx1 - xx));
				b = yy - (a * xx);
				c = (a * x + b);
				printf("yyyyyy:	a:%f	b:%f	c:%f\n", a ,b ,c);
				if (x > 0 && x < 1920 && c < 1080 && 0 < c)
					my_mlx_pixel_put(&img, x, c, 0x00FF0000);
				x++;
			}
		}
		n++;
	}
	mlx_put_image_to_window(t.mlx, t.mlx_win, img.img, 0, 0);
	mlx_hook(t.mlx_win, 2, KeyPressMask, &close_window, &t);
	mlx_loop(t.mlx);
	return (0);
}
