/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:23:28 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/14 14:24:36 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	cond(int col, int row, int x, int y)
{
	if ((row == 1 && col == 1) || (row == y && col == x))
	{
		ft_putchar('A');
	}
	else if ((row == 1 && col == x) || (row == y && col == 1))
	{
		ft_putchar('C');
	}
	else if (row == 1 || row == y || col == 1 || col == x)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int		row;
	int		col;

	if (x <= 0 || y <= 0)
	{
		return ;
	}
	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			cond(col + 1, row + 1, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
