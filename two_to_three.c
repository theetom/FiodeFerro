/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_to_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:59:55 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/20 16:06:32 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void two_to_three(int **numbers)
{
	int n;
	int xx;
	int xx1;
	int yy;
	int yy1;
	int x;
	int y;
	int scale;
	n = 0;
	while(numbers[n])
	{
		scale = 160;
		// printf("%i \n", n);
		
		xx = (t.img_w/2 + scale * ((numbers[n][0]) * cos(120) + (numbers[n][1]) * cos(120 + 2) + (numbers[n][2]) * cos(120 - 2)));
		yy = (t.img_h/2 + scale * ((numbers[n][0]) * sin(120) + (numbers[n][1]) * sin(120 + 2) + (numbers[n][2]) * sin(120 - 2)));
		// printf("x:%d	y:%d	z:%d	xx:%f	yy:%f\n", numbers[n][0], numbers[n][1], numbers[n][2], xx, yy);
		if (xx > 0 && xx < t.img_w && yy < t.img_h && 0 < yy)
			my_mlx_pixel_put(&img, xx, yy, 0x00FFFFFF);
		if (numbers[n + 1])
		{
			xx1 = (t.img_w/2 + scale * ((numbers[n + 1][0]) * cos(120) + (numbers[n + 1][1]) * cos(120 + 2) + (numbers[n + 1][2]) * cos(120 - 2)));
			yy1 = (t.img_h/2 + scale * ((numbers[n + 1][0]) * sin(120) + (numbers[n + 1][1]) * sin(120 + 2) + (numbers[n + 1][2]) * sin(120 - 2)));
			// printf("xx1:%f	yy1:%f\n", xx1, yy1);
			x = xx;
			while (x < xx1)
			{
				a = ((yy1 - yy) / (xx1 - xx));
				b = yy - (a * xx);
				c = (a * x + b);
				// printf("xxxxxx:	a:%f	b:%f	c:%f\n", a ,b ,c);
				if (x > 0 && x < t.img_w && c < t.img_h && 0 < c)
					my_mlx_pixel_put(&img, x, c, 0x00FFFFFF);
				x++;
			}
		}
		if (numbers[n - count_in_line] && n >= count_in_line)
		{
			xx1 = (1920/2 + scale * ((numbers[n - count_in_line][0]) * cos(120) + (numbers[n - count_in_line][1]) * cos(120 + 2) + (numbers[n - count_in_line][2]) * cos(120 - 2)));
			yy1 = (1080/2 + scale * ((numbers[n - count_in_line][0]) * sin(120) + (numbers[n - count_in_line][1]) * sin(120 + 2) + (numbers[n - count_in_line][2]) * sin(120 - 2)));
			// printf("xx1:%f	yy1:%f\n", xx1, yy1);
			x = xx;
			while (x < xx1)
			{ 
				a = ((yy1 - yy) / (xx1 - xx));
				b = yy - (a * xx);
				c = (a * x + b);
				// printf("yyyyyy:	a:%f	b:%f	c:%f\n", a ,b ,c);
				if (x > 0 && x < 1920 && c < 1080 && 0 < c)
					my_mlx_pixel_put(&img, x, c, 0x00FFFFFF);
				x++;
			}
		}
		n++;
	}
}