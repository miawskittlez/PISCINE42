/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:48:07 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/21 12:21:49 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	ft_strlen(char *str);
int	is_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_nbrlen(long nb, int base_len)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int nbr, char *base)
{
	long	nb;
	int		len;
	int		base_len;
	char	*res;

	nb = nbr;
	base_len = ft_strlen(base);
	len = ft_nbrlen(nb, base_len);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb == 0)
		res[0] = base[0];
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[--len] = base[nb % base_len];
		nb = nb / base_len;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (!is_base(base_from) || !is_base(base_to))
	{
		return (NULL);
	}
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to));
}

// int	main(void)
// {
// 	char	*res;

// 	res = ft_convert_base("   --+-42", "0123456789", "01");
// 	printf("%s\n", res);
// 	free(res);
// 	return (0);
// }