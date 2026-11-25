/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:05:02 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/14 14:12:35 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	cond(int col, int row, int x, int y)
{
	if ((row == 1 || row == y) && (col == 1 || col == x))
	{
		ft_putchar('o');
	}
	else if (row == 1 || row == y)
	{
		ft_putchar('-');
	}
	else if (col == 1 || col == x)
	{
		ft_putchar('|');
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
