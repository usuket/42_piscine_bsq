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

typedef	struct		s_validator
{
	int		row_counter;
	int		col_counter;
	int		invalid_cell;
	int		invalid_width;
	int		invalid_flag;
	int		col_checker;
	int		line_num;
	int		i;
	char	*first_line;
	char	buffer;
	int		fd;
}					t_map_valid;

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

void				set_meta(t_meta *meta, int fd);
void				count_width(t_meta *meta, int fd);
void				read_stdin(void);

void				count_square(t_meta meta, t_cell *cell_array);
t_biggest			check_biggest_square(t_cell *cell_array);
int					is_biggest_cells(t_meta meta, int i, t_biggest biggest);
int					map_is_valid(char *file_path, t_meta *meta);

void				init_valid(t_map_valid *val);
void				width_is_valid(t_map_valid *val, int i1, int i2);
void				cell_is_valid(t_map_valid *val, t_meta *meta, char c);
void				set_valid_1(t_map_valid *val, t_meta *meta);
void				set_valid_2(t_map_valid *val, t_meta *meta);

#endif
