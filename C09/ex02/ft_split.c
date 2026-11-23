/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilasita <lilasita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:44:05 by lilasita          #+#    #+#             */
/*   Updated: 2026/11/23 09:34:55 by lilasita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	ft_contains(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (ft_contains(str[i + 1], charset) == 1 || str[i + 1] == '\0')
		{
			if (ft_contains(str[i], charset) == 0)
			{
				res++;
			}
		}
		i++;
	}
	return (res);
}

int	ft_strncpy(char *dest, char *src, int nb)
{
	int	i;

	i = 0;
	while (src[i] && i < nb)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (0);
}

int	ft_fill(char **token_v, char *str, char *charset)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (str[i])
	{
		len = 0;
		while (str[i] && ft_contains(str[i], charset) == 1)
			i++;
		while (str[i] && ft_contains(str[i], charset) == 0)
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			token_v[j] = malloc(sizeof(char) * len + 1);
			if (!token_v[j])
				return (0);
			ft_strncpy(token_v[j++], &str[i - len], len);
		}
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**token_v;
	int		size;

	size = ft_count_word(str, charset);
	token_v = malloc(sizeof(char *) * (size + 1));
	if (!token_v)
	{
		return (NULL);
	}
	token_v[size] = NULL;
	if (ft_fill(token_v, str, charset) == 0)
	{
		return (NULL);
	}
	return (token_v);
}

// void ft_putstr(char *str)
// {
//     int i = 0;
//     while(str[i])
//     {
//         write(1, &str[i], 1);
//         i++;
//     }
// }
// int main(void)
// {
//     char **v = ft_split("5a   bla2bla5 blaaa6   bla    bla  4 ", " 256");
//     int i = 0;
//     while(v[i] != NULL)
//     {
//         ft_putstr(v[i]);
//         write(1, "\n", 1);
//         i++;
//     }
// }