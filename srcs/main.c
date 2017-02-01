/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:20:19 by ysakakib          #+#    #+#             */
/*   Updated: 2017/01/30 14:21:10 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <bsq_header.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1
#define MEM_BUF 20000

t_cell				*read_on_memory(int fd, t_meta meta)
{
	t_cell		*cell_array;
	char		buffer;
	int			i;

	cell_array = malloc(sizeof(t_cell) * (meta.width * meta.height + MEM_BUF));
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			break ;
	}
	i = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer != '\n')
		{
			cell_array[i].cell = buffer;
			i++;
		}
	}
	cell_array[i].cell = '\0';
	return (cell_array);
}

int					file_read(char *file_path, t_meta *meta)
{
	int				fd;
	t_cell			*matrix;
	t_biggest		biggest;

	fd = open(file_path, O_RDONLY);
	matrix = read_on_memory(fd, *meta);
	count_square(*meta, matrix);
	biggest = check_biggest_square(matrix);
	display_cells(*meta, matrix, biggest);
	free(matrix);
	close(fd);
	return (0);
}

int					main(int argc, char **argv)
{
	t_meta			meta;
	int				i;

	if (argc < 2)
	{
		read_stdin();
		if (map_is_valid("./tmp/tmp", &meta))
			file_read("./tmp/tmp", &meta);
		else
			write(2, "map error\n", 10);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (map_is_valid(argv[i], &meta))
			file_read(argv[i], &meta);
		else
			write(2, "map error\n", 10);
		i++;
	}
	return (0);
}
