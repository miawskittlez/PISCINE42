/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:48:48 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/14 18:07:09 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	lend;
	unsigned int	lens;
	unsigned int	i;

	lend = 0;
	while (lend < size && dest[lend])
	{
		lend++;
	}
	lens = ft_strlen(src);
	if (lend == size)
	{
		return (size + lens);
	}
	i = 0;
	while (i < lens && i < size - lend - 1)
	{
		dest[lend + i] = src[i];
		i++;
	}
	dest[lend + i] = '\0';
	return (lend + lens);
}

// int main(void)
// {
// 	printf("%u", ft_strlcat((strdup("hello")), (strdup("yes")), 8));
// }
