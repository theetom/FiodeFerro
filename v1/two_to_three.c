/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_to_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:12:56 by toferrei          #+#    #+#             */
/*   Updated: 2024/08/30 16:31:59 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* void x_line(int n, int **data->tdp, double xx, double yy, t_data *data)
{
	double		xx1;
	double		yy1;
	double		a;
	double		b;
	double		c;
	double		x;
	double		temp;

	temp = 0;
	
	xx1 = (data->position_w + data->scale * ((data->tdp[n + 1][0]) * cos(120) + (data->tdp[n + 1][1]) * cos(120 + 2) + (data->tdp[n + 1][2]) * cos(120 - 2)));
	yy1 = (data->position_h + data->scale * ((data->tdp[n + 1][0]) * sin(120) + (data->tdp[n + 1][1]) * sin(120 + 2) + (data->tdp[n + 1][2]) * sin(120 - 2)));
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
		if (x > 0 && x < data->t.img_w && c < data->t.img_h && 0 < c)
			my_mlx_pixel_put(&data->img, x, c, 0xFFFFFF);
		x += 0.01;
	}
}

void y_line(int n, int **data->tdp, double xx, double yy, t_count_data *data)
{
	double		xx1;
	double		yy1;
	double		a;
	double		b;
	double		c;
	double		x;
	int			temp;

	temp = 0;
	
	xx1 = (data->position_w + data->scale * ((data->tdp[n - data->line_l][0]) * cos(120) + (data->tdp[n - data->line_l][1]) * cos(120 + 2) + (data->tdp[n - data->line_l][2]) * cos(120 - 2)));
	yy1 = (data->position_h + data->scale * ((data->tdp[n - data->line_l][0]) * sin(120) + (data->tdp[n - data->line_l][1]) * sin(120 + 2) + (data->tdp[n - data->line_l][2]) * sin(120 - 2)));
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
			my_mlx_pixel_put(&data->img, x, c, 0x00FFFFFF);
		x += 0.01;
	}
}
 */

// void two_to_three(t_data *data)
// {
// 	int		n;
// 	double	xx;
// 	double	yy;
// 	double	temp;
	
// 	n = 0;
// 	temp = 0;
// 	while(data->tdp[n])
// 	{
// 		xx = (data->position_w + data->scale * ((data->tdp[n][0]) * cos(120) + (data->tdp[n][1]) * cos(120 + 2) + (data->tdp[n][2]) * cos(120 - 2)));
// 		yy = (data->position_h + data->scale * ((data->tdp[n][0]) * sin(120) + (data->tdp[n][1]) * sin(120 + 2) + (data->tdp[n][2]) * sin(120 - 2)));
// 		if (xx > 0 && xx < data->img_w && yy < data->img_h && 0 < yy)
// 			my_mlx_pixel_put(data, xx, yy, 0x00FFFFFF);
// /* 		if (data->tdp[n + 1] && (n + 1) % data->line_l != 0)
// 			x_line(n, data->tdp, xx, yy, data);
// 		if (data->tdp[n - data->line_l] && n >= data->line_l)
// 			y_line(n, data->tdp, xx, yy, data); */
// 		n++;
// 	}
// }
