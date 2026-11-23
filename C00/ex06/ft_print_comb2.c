/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:33:05 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/09 18:11:22 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nb)
{
	ft_putchar(nb / 10 + 48);
	ft_putchar(nb % 10 + 48);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = 1 + i;
		while (j <= 99)
		{
			ft_putnbr(i);
			write(1, " ", 1);
			ft_putnbr(j);
			if (!(j == 99 && i == 98))
			{
				write(1, ", ", 2);
			}
			j++;
		}
		i++;
	}
}
