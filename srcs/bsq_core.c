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

typedef struct		s_cell_crawler
{
	int				i;
	int				size;
	int				target_y;
	int				target_x;
}					t_cell_crawler;

void				fill_cell(t_cell_crawler *c, t_meta m, t_cell *cells, int i)
{
	cells[i].size = c->size;
}

void				crawl_cell(t_meta meta, t_cell *cells, int index)
{
	t_cell_crawler	c;
	t_point			point;

	point = index_to_point(meta, index);
	c.size = 1;
	while (1)
	{
		c.i = -1;
		while (c.i++ <= c.size)
		{
			c.target_y = index + meta.width * c.i + c.size;
			c.target_x = index + meta.width * c.size + c.i;
			if (point.x + c.i >= meta.width || point.y + c.i >= meta.height
				|| cells[c.target_y].cell == meta.obstacle
				|| cells[c.target_x].cell == meta.obstacle)
				fill_cell(&c, meta, cells, index);
			else
				continue;
			return ;
		}
		c.size++;
	}
}

void				count_square(t_meta meta, t_cell *cells)
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
			if (cells[index].cell == meta.empty && cells[index].size == 0)
			{
				crawl_cell(meta, cells, index);
			}
			x++;
		}
		y++;
	}
}

t_biggest			check_biggest_square(t_cell *cells)
{
	int			i;
	int			index;
	int			size;
	t_biggest	biggest;

	biggest.size = 0;
	biggest.index = 0;
	i = 0;
	index = 0;
	size = 0;
	while (cells[i].cell)
	{
		if (cells[i].size > size)
		{
			size = cells[i].size;
			index = i;
		}
		i++;
	}
	biggest.size = size;
	biggest.index = index;
	return (biggest);
}

int					is_biggest_cells(t_meta meta, int i, t_biggest biggest)
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
