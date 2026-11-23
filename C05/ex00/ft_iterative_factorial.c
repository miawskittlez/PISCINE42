/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:39:54 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/16 16:24:24 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	res;

	n = 1;
	res = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (n <= nb)
	{
		res = res * n;
		n++;
	}
	return (res);
}
