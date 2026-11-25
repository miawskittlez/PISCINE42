/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:19:00 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/25 14:19:00 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

t_stock_str	*ft_strs_to_tab(int ac, char **av);
void		ft_show_tab(struct s_stock_str *par);

int	main(int argc, char **argv)
{
	t_stock_str	*tab;
	int			i;

	tab = ft_strs_to_tab(argc - 1, argv + 1);
	if (!tab)
	{
		write(2, "ft_strs_to_tab failed\n", 22);
		return (1);
	}
	ft_show_tab(tab);
	i = 0;
	while (i < argc - 1)
		free(tab[i++].copy);
	free(tab);
	return (0);
}
