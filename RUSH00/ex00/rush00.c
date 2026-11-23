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

	row = 1;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			cond(col, row, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
