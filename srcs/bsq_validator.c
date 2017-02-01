/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 03:23:07 by ysakakib          #+#    #+#             */
/*   Updated: 2017/02/01 03:23:09 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq_header.h>
#include <ft_header.h>
#include <stdlib.h>
#include <unistd.h>

void				init_valid(t_map_valid *val)
{
	val->row_counter = 0;
	val->col_counter = 0;
	val->invalid_flag = 0;
	val->col_checker = 0;
	val->line_num = 0;
	val->i = 0;
	val->buffer = '\0';
	val->fd = 0;
}

void				width_is_valid(t_map_valid *val, int i1, int i2)
{
	if (i1 == 0)
		return ;
	else if (i1 == i2)
		return ;
	val->invalid_flag = 1;
}

void				cell_is_valid(t_map_valid *val, t_meta *meta, char c)
{
	if (meta->empty == c || meta->obstacle == c ||
		meta->full == c || c == '\0' || c == '\n')
		return ;
	else
		val->invalid_flag = 1;
}

void				set_valid_1(t_map_valid *val, t_meta *meta)
{
	char *first_line;

	first_line = malloc(sizeof(char) * 20000);
	while (read(val->fd, &val->buffer, 1) != 0)
	{
		if (('0' <= val->buffer && val->buffer <= '9')
			|| val->buffer == '\0' || val->buffer == '\n')
			first_line[val->i] = val->buffer;
		else
		{
			meta->empty = val->buffer;
			read(val->fd, &meta->obstacle, 1);
			read(val->fd, &meta->full, 1);
			break ;
		}
		val->i = val->i + 1;
	}
	first_line[val->i] = '\0';
	val->line_num = ft_atoi(first_line);
	free(first_line);
}

void				set_valid_2(t_map_valid *val, t_meta *meta)
{
	while (read(val->fd, &val->buffer, 1) != 0)
	{
		cell_is_valid(val, meta, val->buffer);
		if (val->buffer == '\0')
			break ;
		if (val->buffer == '\n')
		{
			val->row_counter++;
			width_is_valid(val, val->col_checker, val->col_counter);
			val->col_checker = val->col_counter;
			val->col_counter = 0;
		}
		val->col_counter = val->col_counter + 1;
	}
}
