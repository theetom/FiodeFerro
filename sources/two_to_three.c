/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_to_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:12:56 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/06 13:22:35 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void math_mather(t_conv *pt, t_data *data)
{
	pt->a = ((pt->yy1 - pt->yy) / (pt->xx1 - pt->xx));
	pt->b = pt->yy - (pt->a * pt->xx);
	pt->c = (pt->a * pt->x + pt->b);
	if (pt->x > 0 && pt->x < data->img_w && pt->c < data->img_h && 0 < pt->c)
		my_mlx_pixel_put(data, pt->x, pt->c, 0xFFFFFF);
	pt->x += 0.01;
}

static void swap_point(t_conv *pt)
{
	pt->temp = pt->xx1;
	pt->xx1 = pt->xx;
	pt->xx = pt->temp;
	pt->temp = pt->yy1;
	pt->yy1 = pt->yy;
	pt->yy = pt->temp;
}

static void x_line(int n, t_conv *pt, t_data *data)
{
	pt->xx1 = two_d_cos(data->position_w, data->scale, data, n);
	pt->yy1 = two_d_sin(data->position_h, data->scale, data, n);
	if (pt->xx1 < pt->xx)
		swap_point(pt);
	pt->x = pt->xx;
	while (pt->x < pt->xx1)
		math_mather(pt, data);
}

static void y_line(int n, t_conv *pt, t_data *data)
{
	pt->xx1 = two_d_cos(data->position_w, data->scale, data, n);;
	pt->yy1 = two_d_sin(data->position_h, data->scale, data, n);
	if (pt->xx1 < pt->xx)
		swap_point(pt);
	pt->x = pt->xx;
	while (pt->x < pt->xx1)
		math_mather(pt, data);
}


void two_to_three(t_data *data)
{
	int		n;
	t_conv	pt;
	
	n = 0;
	while(n < data->count)
	{
		pt.xx = two_d_cos(data->position_w, data->scale, data, n);
		pt.yy = two_d_sin(data->position_h, data->scale, data, n);
		if (pt.xx > 0 && pt.xx < data->img_w && pt.yy < data->img_h && 0 < pt.yy)
			my_mlx_pixel_put(data, pt.xx, pt.yy, 0x00FFFFFF);
		if (n < data->count - 1)
			if (data->tdp[n + 1] && (n + 1) % data->line_l != 0)
				x_line(n + 1, &pt, data);
		if (n >= data->line_l)
			if (data->tdp[n - data->line_l])
				y_line(n - data->line_l, &pt, data);
		n++;
	}
}