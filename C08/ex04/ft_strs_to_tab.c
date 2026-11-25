/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:10:52 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/25 14:10:53 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free_tab(t_stock_str *tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
}

int	ft_set_entry(t_stock_str *entry, char *str)
{
	if (!str)
		return (0);
	entry->size = ft_strlen(str);
	entry->str = str;
	entry->copy = ft_strdup(str);
	if (!entry->copy)
		return (0);
	return (1);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	if (ac < 0 || (ac > 0 && !av))
		return (NULL);
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (!ft_set_entry(&tab[i], av[i]))
		{
			ft_free_tab(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
