/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:23:25 by caliaga-          #+#    #+#             */
/*   Updated: 2022/12/02 14:39:25 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_rows(char const *s, char c, size_t *row)
{
	size_t	nb;
	size_t	i;

	row = 0;
	if (!s)
		return (0);
	i = -1;
	nb = 0;
	while (s[++i] != '\0')
		if (s[i] != c)
			if (i == 0 || s[i - 1] == c)
				nb++;
	return (nb);
}

static size_t	ft_start_col(char const *s, char c, size_t *i)
{
	size_t	k;
	size_t s_c;

	s_c = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			if (i == 0 || s[i - 1] == c)
			{
				s_c = i;
				break;
			}
		i++;
	}
 	return (s_c);
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
	size_t	i;
	size_t	row;
	size_t	start_col;
	size_t	cols;
	char	**split;

	row = 0;
	i = 0;
	split = (char **) malloc ((ft_rows(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (row < ft_rows(s,c))
	{
		start_col = ft_start_col(s, c, &i);
		while (s[i] != c)
			
		split[row] = malloc ()
			ft_cols(s, c, start[row]);
		if (!split[row])
			return (ft_check(split, row));
		row++;
	}
	split[row] = 0;
	if (start)
		free(start);
	return (split);
}
