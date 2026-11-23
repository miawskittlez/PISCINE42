/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:51:17 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/14 11:39:05 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	int	x;
	int	y;

	if (ac < 3)
	{
		write(1, "TOO FEW ARGUMENTS\n", 18);
		return (0);
	}
	if (ac > 3)
	{
		write(1, "TOO MANY ARGUMENTS\n", 19);
		return (0);
	}
	if (ac == 3)
	{
		x = ft_atoi(av[1]);
		y = ft_atoi(av[2]);
		if (x > 0 && y > 0)
		{
			rush(x, y);
		}
	}
	return (0);
}
