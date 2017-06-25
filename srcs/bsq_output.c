/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:50:30 by ysakakib          #+#    #+#             */
/*   Updated: 2017/02/01 13:50:39 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <bsq_header.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void				write_buffer(char *buffer, int size)
{
	buffer[size] = '\n';
	write(1, buffer, (size + 1));
}

char				define_cell(t_meta m, t_cell *cells, int i, t_biggest big)
{
	if (is_biggest_cells(m, i, big))
		return (m.full);
	else if (cells[i].cell == m.obstacle)
		return (m.obstacle);
	else
		return (m.empty);
}

void				display_cells(t_meta meta, t_cell *cells, t_biggest big)
{
	int		i;
	int		x;
	int		y;
	char	*buffer;

	buffer = (char*)malloc(sizeof(char) * (meta.width + 1));
	y = 0;
	while (y < meta.height)
	{
		x = 0;
		while (x < meta.width)
		{
			i = yx_to_index(meta, y, x);
			if (cells[i].cell == '\0')
			{
				write_buffer(buffer, x);
				free(buffer);
				return ;
			}
			buffer[x] = define_cell(meta, cells, i, big);
			x++;
		}
		write_buffer(buffer, x);
		y++;
	}
}
