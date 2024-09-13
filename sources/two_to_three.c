/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_to_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:12:56 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/13 13:18:27 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void math_mather(t_conv *pt, t_data *data, int n)
{
	pt->a = ((pt->yy1 - pt->yy) / (pt->xx1 - pt->xx));
	pt->b = pt->yy - (pt->a * pt->xx);
	pt->c = (pt->a * pt->x + pt->b);
	if (pt->x > 0 && pt->x < data->img_w && pt->c < data->img_h && 0 < pt->c)
		my_mlx_pixel_put(data, pt->x, pt->c, colors(data, n));
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

static void line(int n, t_conv *pt, t_data *data)
{
	int	trigger;

	trigger = 0;
	pt->xx1 = two_d_cos(data->position_w, data->scale, data, n);
	pt->yy1 = two_d_sin(data->position_h, data->scale, data, n);
	if (pt->xx1 < pt->xx)
	{
		swap_point(pt);
		trigger++;
	}
	pt->x = pt->xx;
	while (pt->x < pt->xx1)
		math_mather(pt, data, n);
	if (trigger)
		swap_point(pt);
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
			my_mlx_pixel_put(data, pt.xx, pt.yy, colors(data, n));
		if (n < data->count - 1 && (n + 1) % data->line_l != 0)
			line(n + 1, &pt, data);
		if (n + data->line_l < data->count)
			line(n + data->line_l, &pt, data);
		n++;
	}
	printf("\n");
}
