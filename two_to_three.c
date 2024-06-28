/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_to_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:59:55 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/28 17:05:27 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void x_line(int n, int **numbers, double xx, double yy, t_count_data *count_values)
{
	double		xx1;
	double		yy1;
	double		a;
	double		b;
	double		c;
	double		x;
	double		temp;

	temp = 0;
	
	xx1 = (count_values->position_w + count_values->scale * ((numbers[n + 1][0]) * cos(120) + (numbers[n + 1][1]) * cos(120 + 2) + (numbers[n + 1][2]) * cos(120 - 2)));
	yy1 = (count_values->position_h + count_values->scale * ((numbers[n + 1][0]) * sin(120) + (numbers[n + 1][1]) * sin(120 + 2) + (numbers[n + 1][2]) * sin(120 - 2)));
	if (xx1 < xx)
	{
		temp = xx1;
		xx1 = xx;
		xx = temp;
		temp = yy1;
		yy1 = yy;
		yy = temp;
	}
	x = xx;
	while (x < xx1)
	{
		a = ((yy1 - yy) / (xx1 - xx));
		b = yy - (a * xx);
		c = (a * x + b);
		if (x > 0 && x < count_values->t.img_w && c < count_values->t.img_h && 0 < c)
			my_mlx_pixel_put(&count_values->img, x, c, 0x00FFFFFF);
		x += 0.01;
	}
}

void y_line(int n, int **numbers, double xx, double yy, t_count_data *count_values)
{
	double		xx1;
	double		yy1;
	double		a;
	double		b;
	double		c;
	double		x;
	int			temp;

	temp = 0;
	
	xx1 = (count_values->position_w + count_values->scale * ((numbers[n - count_values->count_in_line][0]) * cos(120) + (numbers[n - count_values->count_in_line][1]) * cos(120 + 2) + (numbers[n - count_values->count_in_line][2]) * cos(120 - 2)));
	yy1 = (count_values->position_h + count_values->scale * ((numbers[n - count_values->count_in_line][0]) * sin(120) + (numbers[n - count_values->count_in_line][1]) * sin(120 + 2) + (numbers[n - count_values->count_in_line][2]) * sin(120 - 2)));
	if (xx1 < xx)
	{
		temp = xx1;
		xx1 = xx;
		xx = temp;
		temp = yy1;
		yy1 = yy;
		yy = temp;
	}
	x = xx;
	while (x < xx1)
	{ 
		a = ((yy1 - yy) / (xx1 - xx));
		b = yy - (a * xx);
		c = (a * x + b);
		if (x > 0 && x < 1920 && c < 1080 && 0 < c)
			my_mlx_pixel_put(&count_values->img, x, c, 0x00FFFFFF);
		x += 0.01;
	}
}

void two_to_three(int **numbers, t_count_data *count_values)
{
	int		n;
	double	xx;
	double	yy;
	double	temp;
	
	n = 0;
	temp = 0;
	while(numbers[n])
	{
		xx = (count_values->position_w + count_values->scale * ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2)));
		yy = (count_values->position_h + count_values->scale * ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2)));
		if (xx > 0 && xx < count_values->t.img_w && yy < count_values->t.img_h && 0 < yy)
			my_mlx_pixel_put(&count_values->img, xx, yy, 0x00FFFFFF);
		if (numbers[n + 1] && (n + 1) % count_values->count_in_line != 0)
			x_line(n, numbers, xx, yy, count_values);
		if (numbers[n - count_values->count_in_line] && n >= count_values->count_in_line)
			y_line(n, numbers, xx, yy, count_values);
		n++;
	}
}
