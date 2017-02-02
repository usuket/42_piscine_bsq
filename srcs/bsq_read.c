/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:12:12 by ysakakib          #+#    #+#             */
/*   Updated: 2017/02/01 17:12:14 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <bsq_header.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define MEM_BUF 20000

int					read_on_memory_impl(int fd, t_cell *cell_array)
{
	char		str_buffer[10000];
	int			read_byte;
	int			length;
	int			i;

	length = 0;
	while (1)
	{
		read_byte = read(fd, &str_buffer, 10000);
		i = -1;
		if (read_byte > 0)
		{
			while (i++ < read_byte)
			{
				if (str_buffer[i] != '\n')
				{
					cell_array[length].cell = str_buffer[i];
					length++;
				}
			}
		}
		else
			break ;
	}
	return (length);
}

t_cell				*read_on_memory(int fd, t_meta meta)
{
	t_cell		*cell_array;
	char		buffer;
	int			length;

	cell_array = malloc(sizeof(t_cell) * (meta.width * meta.height + MEM_BUF));
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			break ;
	}
	length = read_on_memory_impl(fd, cell_array);
	cell_array[length].cell = '\0';
	return (cell_array);
}
