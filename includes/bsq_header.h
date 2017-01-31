/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:14:38 by ysakakib          #+#    #+#             */
/*   Updated: 2017/01/31 15:14:45 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_H
# define BSQ_HEADER_H

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_cell
{
	char	cell;
	int		size;
}					t_cell;

typedef struct		s_biggest
{
	int		index;
	int		size;
}					t_biggest;

typedef struct		s_meta
{
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	full;
}					t_meta;

int					yx_to_index(t_meta meta, int y, int x);
int					point_to_index(t_meta meta, t_point point);
int					index_to_y(t_meta meta, int index);
int					index_to_x(t_meta meta, int index);
t_point				index_to_point(t_meta meta, int index);

int					crawl_cell(t_meta meta, t_cell *cell_array, int index);
void				count_square(t_meta meta, t_cell *cell_array);
t_biggest			check_biggest_square(t_meta meta, t_cell *cell_array);
int					is_biggest_cells(t_meta meta, int i, t_biggest biggest);

#endif