/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:02:22 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/19 17:52:21 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	size;

	i = 0;
	if (min >= max)
		return (NULL);
	else
		size = (max - min) + 1;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
