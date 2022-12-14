/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:23:25 by caliaga-          #+#    #+#             */
/*   Updated: 2022/11/30 13:29:11 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	*ft_rows(char const *s, char c, size_t *rows)
{
	size_t	nb;
	size_t	i;
	size_t	k;
	size_t	*f;

	i = -1;
	nb = 0;
	while (s[++i] != '\0')
		if (s[i] != c)
			if (i == 0 || s[i - 1] == c)
				nb++;
	*rows = nb;
	i = -1;
	k = -1;
	f = malloc (nb * sizeof(size_t));
	if (!f)
		return (NULL);
	while (s[++i] != '\0')
		if (s[i] != c)
			if (i == 0 || s[i - 1] == c)
				f[++k] = i;
	return (f);
}

static char	*ft_cols(const char *s, char c, size_t start)
{
	size_t	cols;
	size_t	k;
	char	*f;
	size_t	i;

	k = start;
	cols = 0;
	while (s[k] != c && s[k] != '\0')
	{
		cols++;
		k++;
	}
	i = 0;
	k = start;
	f = malloc ((cols + 1) * sizeof(char));
	if (!f)
		return (NULL);
	while (s[k] != c && s[k] != '\0')
		f[i++] = s[k++];
	f[i] = '\0';
	return (f);
}

static char	**ft_check(char **split, size_t row)
{
	while (row-- > 0)
	{
		if (split[row])
			free(split[row]);
	}
	if (split)
		free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	rows;
	size_t	row;
	size_t	*starts;
	char	**split;

	starts = ft_rows(s, c, &rows);
	if (!starts)
		return (0);
	row = 0;
	if (!s)
		return (NULL);
	split = (char **) malloc ((rows + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (row < rows)
	{
		split[row] = ft_cols(s, c, starts[row]);
		if (!split[row])
			return (ft_check(split, row));
		row++;
	}
	split[row] = 0;
	if (starts)
		free(starts);
	return (split);
}
