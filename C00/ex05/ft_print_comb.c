/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:22:29 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/09 18:11:45 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar(nbr % 10 + 48);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = 1 + i;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_putnbr(i);
				ft_putnbr(j);
				ft_putnbr(k);
				if (!(k == 9 && j == 8 && i == 7))
					write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}
