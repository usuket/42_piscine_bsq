/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   culculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:13:42 by ysakakib          #+#    #+#             */
/*   Updated: 2017/01/31 15:13:45 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq_header.h>

int					yx_to_index(t_meta meta, int y, int x)
{
	return ((meta.width * y) + x);
}

int					point_to_index(t_meta meta, t_point point)
{
	return ((meta.width * point.y) + point.x);
}

int					index_to_y(t_meta meta, int index)
{
	return (index / meta.width);
}

int					index_to_x(t_meta meta, int index)
{
	return (index % meta.width);
}

t_point				index_to_point(t_meta meta, int index)
{
	t_point point;

	point.y = index / meta.width;
	point.x = index % meta.width;
	return (point);
}
