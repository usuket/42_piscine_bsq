/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:43:04 by ysakakib          #+#    #+#             */
/*   Updated: 2017/01/17 11:43:06 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	negative_flag;

	number = 0;
	negative_flag = 0;
	i = 0;
	if (str[i] == '-')
		negative_flag = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		number *= 10;
		number += (int)str[i] - '0';
		i++;
	}
	if (negative_flag == 1)
		return (-number);
	else
		return (number);
}
