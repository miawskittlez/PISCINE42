/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:06:00 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/19 17:59:33 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		i++;
	}
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (0);
}

int	ft_total_l(int size, char **strs, char *sep)
{
	int	i;
	int	total_l;

	if (size <= 0)
		return (0);
	i = 0;
	total_l = 0;
	while (i < size)
	{
		total_l += ft_strlen(strs[i]);
		i++;
	}
	total_l += ft_strlen(sep) * size - 1;
	return (total_l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*nstr;

	i = 0;
	nstr = malloc(sizeof(char) * (ft_total_l(size, strs, sep) + 1));
	if (!nstr)
		return (NULL);
	nstr[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(nstr, strs[i]);
		if (i < size - 1)
			ft_strcat(nstr, sep);
		i++;
	}
	return (nstr);
}

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	char *str = ft_strjoin(ac, av, "42");
// 	printf("%s\n", str);
// }