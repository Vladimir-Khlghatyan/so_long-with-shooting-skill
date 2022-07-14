/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:05:42 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:05:45 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**tabfree(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**malloccheck(char **tab)
{
	if (!tab)
		return (NULL);
	return (tab);
}

int	wordcount(const char *s, char c)
{
	int	q;
	int	i;

	q = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	if (s[i++] != '\0')
		q = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			q++;
		i++;
	}
	return (q);
}

int	wordlen(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wc;
	int		i;
	int		t;

	if (!s)
		return (NULL);
	i = -1;
	wc = wordcount(s, c);
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	malloccheck(tab);
	while (++i < wc)
	{
		tab[i] = (char *)malloc(sizeof(char) * (wordlen(s, c) + 1));
		if (!tab[i])
			return (tabfree(tab));
		while (*s == c)
			s++;
		t = 0;
		while (*s != c && *s)
			tab[i][t++] = *s++;
		tab[i][t] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
