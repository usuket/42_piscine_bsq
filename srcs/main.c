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
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1

typedef struct s_point{
	int x;
	int y;
} t_point;

typedef struct s_cell{
	char cell;
	int size;
} t_cell;

typedef struct s_meta{
	int height;
	int width;
	char empty;
	char obstacle;
	char full;
} t_meta;

int		yx_to_index(t_meta meta, int y ,int x)
{
	return ((meta.width * y) + x);
}

int		point_to_index(t_meta meta, t_point	point)
{
	return ((meta.width * point.y) + point.x);
}

int	index_to_y(t_meta meta, int index)
{
	return (index / meta.width);
}

int	index_to_x(t_meta meta, int index)
{
	return (index % meta.width);
}

t_point		index_to_point(t_meta meta, int index)
{
	t_point point;
	point.y = index / meta.width;
	point.x = index % meta.width;
	return (point);
}

t_meta    read_map_meta(int fd)
{
	t_meta meta;
	char buffer;
	int line_count;
	int char_count;
	char *map_length_str;

	map_length_str = malloc(sizeof(char) * (100));
	line_count = 0;
	char_count = 0;

	// read first line
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer == '\n')
			break;
		if ('0' <= buffer && buffer <= '9')
		{
			map_length_str[char_count] = buffer;
			char_count++;
		}
		else
		{
			meta.empty = buffer;
			read(fd, &meta.obstacle, 1);
			read(fd, &meta.full, 1);
			break ;
		}
	}
	// read second line
	read(fd, &buffer, 1); // line break
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer != '\n')
		{
			meta.width++;
		}
		else
			break;
	}
	meta.height = ft_atoi(map_length_str);
	printf("meta height:%d\n", meta.height);
	printf("meta width:%d\n", meta.width);
	printf("meta empty:%c\n", meta.empty);
	printf("meta obstacle:%c\n", meta.obstacle);
	printf("meta full:%c\n", meta.full);
	return meta;
}

t_cell 	*read_on_memory(int fd , t_meta meta)
{
	int matrix_size;
	t_cell *cell_array;
	char buffer;
	int i;

	matrix_size = meta.width * meta.height;
	cell_array = malloc(10000);

	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			break;
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
	return (cell_array);
}


int 	crawl_cell(t_meta meta,t_cell *cell_array,int index)
{
	int i;
	int size;
	t_point point = index_to_point(meta,index);
	size = 1;
	while(1)
	{
		i = 0;
		while(i <= size)
		{
			if(point.x + i >= meta.width || point.y + i >= meta.height)
			{
				cell_array[index].size = size;
				return (0);
			}
			int target_y = index + meta.width * i + size;
			int target_x = index + meta.width * size + i;
			if(cell_array[target_y].cell == meta.obstacle || cell_array[target_x].cell == meta.obstacle)
			{
					cell_array[index].size = size;
					return (size);
			}
			i++;
		}
		size++;
	}
}

void 	count_square(t_meta meta,t_cell *cell_array)
{
	int y;
	int x;

	y = 0;
	while(y < meta.height)
	{
		x = 0;
		while (x < meta.width)
		{
			int index = yx_to_index(meta, y, x);
			if(cell_array[index].cell == meta.empty)
			{
				crawl_cell(meta, cell_array, index);
			}
			printf("y:%d x:%d size:%d\n", y, x, cell_array[index].size);
			x++;
		}
		y++;
	}
}

void 	display_cells(t_meta meta,t_cell *cell_array)
{
	int i;

	i = 0;
	while (cell_array[i].cell) {

		if (cell_array[i].cell == meta.empty) {
			printf("%c", meta.full);
		}else if (cell_array[i].cell == meta.obstacle){
			printf("%c", meta.obstacle);
		}else{
			printf("%c", meta.empty);
		}
		if (i != 0 && (i + 1) % meta.width == 0)
			printf("\n");
		i++;
	}
}

//void    display_file(int fd)
//{
//	char buffer;
//	int line_count;
//
//	line_count= 0;
//	while (read(fd, &buffer, BUF_SIZE) != 0)
//	{
//		if (buffer == '\n')
//			line_count++;
//		write(1, &buffer, BUF_SIZE);
//	}
//	printf("line_count:%d\n",line_count);
//}

int	file_read(char *file_path)
{
	int				fd;
	t_meta			meta;
	t_cell			*matrix;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File open failed.\n");
		return (1);
	}
	meta = read_map_meta(fd);
	close(fd);
	fd = open(file_path, O_RDONLY);
	matrix = read_on_memory(fd, meta);
	count_square(meta, matrix);
	display_cells(meta, matrix);
	free(matrix);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
		printf("need argv\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		file_read(argv[i]);
		printf("\n");
		i++;
	}
	return (0);
}
