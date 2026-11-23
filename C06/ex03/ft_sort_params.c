/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:54:59 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/10 18:34:40 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	sort(int ac, char **av)
{
	int		i;
	int		j;
	char	*temp;

	if (ac > 1)
	{
		i = 1;
		while (i < ac - 1)
		{
			j = i + 1;
			while (j < ac)
			{
				if (ft_strcmp(av[i], av[j]) > 0)
				{
					temp = av[i];
					av[i] = av[j];
					av[j] = temp;
				}
				j++;
			}
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		sort(ac, av);
		i = 1;
		while (i < ac)
		{
			ft_putstr(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
