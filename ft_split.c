/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:04:05 by skhaliff          #+#    #+#             */
/*   Updated: 2022/08/04 14:19:02 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	nbr_of_words(char const *s, char c)
{
	int	i;
	int	trv;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < (int)ft_strlen(s))
	{
		trv = 0;
		while ((int)ft_strlen(s) != i && s[i] != c)
		{
			trv = 1;
			i++;
		}
		if (trv == 1)
			tmp++;
		i++;
	}
	return (tmp);
}

static int	nbr_of_char(int *j, char const *s, char c)
{
	int	p;

	p = *j;
	while (*j != (int)ft_strlen(s))
	{
		if (s[*j] == c)
			break ;
		(*j)++;
	}
	return (*j - p);
}

static void	filling_tab_str_i(char *tab, char const *s, int j, int temp)
{
	int	t;

	t = 0;
	while (t < j - temp)
	{
		tab[t] = s[temp + t];
		t++;
	}
	tab[t] = 0;
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**tab_str;
	int		j;
	int		temp;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	tab_str = ft_calloc(sizeof(char *), (nbr_of_words(s, c) + 1));
	if (!tab_str)
		return (NULL);
	while (j < (int)ft_strlen(s))
	{
		if (s[j] != c && i < nbr_of_words(s, c))
		{
			temp = j;
			tab_str[i] = malloc(sizeof(char) * (nbr_of_char(&j, s, c) + 1));
			filling_tab_str_i(tab_str[i++], s, j, temp);
		}
		j++;
	}
	return (tab_str);
}
