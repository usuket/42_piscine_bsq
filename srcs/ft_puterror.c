/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 23:08:38 by ysakakib          #+#    #+#             */
/*   Updated: 2017/01/26 23:08:41 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		ft_put_error(char c)
{
	write(2, &c, 1);
	return (0);
}

void	ft_put_error_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_put_error(str[i]);
		i++;
	}
}
