/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:04:35 by zel-baji          #+#    #+#             */
/*   Updated: 2025/02/21 15:22:09 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 1;
	while (*str)
	{
		if (*str && word)
		{
			count++;
			word = 0;
		}
		else if (*str && *str == c)
			word = 1;
		str++;
	}
	return (count);
}

static char	*malloc_word(const char *str, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_s(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;

	if (!s)
		return (NULL);
	ptr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			ptr[i] = malloc_word(s, c);
			if (!ptr[i])
				return (free_s(ptr), NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	return (ptr[i] = NULL, ptr);
}
