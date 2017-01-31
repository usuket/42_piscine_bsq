/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:24:47 by ysakakib          #+#    #+#             */
/*   Updated: 2017/01/31 15:24:49 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq_header.h>

int				crawl_cell(t_meta meta, t_cell *cell_array, int index)
{
	int				i;
	int				size;
	int				target_y;
	int				target_x;
	t_point			point;

	point = index_to_point(meta, index);
	size = 1;
	while (1)
	{
		i = 0;
		while (i <= size)
		{
			if (point.x + i >= meta.width || point.y + i >= meta.height)
			{
				cell_array[index].size = size;
				return (0);
			}
			target_y = index + meta.width * i + size;
			target_x = index + meta.width * size + i;
			if (cell_array[target_y].cell == meta.obstacle
				|| cell_array[target_x].cell == meta.obstacle)
			{
				cell_array[index].size = size;
				return (size);
			}
			i++;
		}
		size++;
	}
}

void			count_square(t_meta meta, t_cell *cell_array)
{
	int index;
	int y;
	int x;

	y = 0;
	while (y < meta.height)
	{
		x = 0;
		while (x < meta.width)
		{
			index = yx_to_index(meta, y, x);
			if (cell_array[index].cell == meta.empty)
			{
				crawl_cell(meta, cell_array, index);
			}
			x++;
		}
		y++;
	}
}

t_biggest		check_biggest_square(t_meta meta, t_cell *cell_array)
{
	int			i;
	int			index;
	int			size;
	t_biggest	biggest;

	i = 0;
	index = 0;
	size = 0;
	while (cell_array[i].cell)
	{
		if (cell_array[i].size > size)
		{
			size = cell_array[i].size;
			index = i;
		}
		i++;
	}
	biggest.size = size;
	biggest.index = index;
	return (biggest);
}

int				is_biggest_cells(t_meta meta, int i, t_biggest biggest)
{
	int count;

	count = 0;
	while (count < biggest.size)
	{
		if (biggest.index + (count * meta.width) <= i &&
			i < biggest.index + biggest.size + (count * meta.width))
		{
			return (1);
		}
		count++;
	}
	return (0);
}
