/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:03:12 by azhadan           #+#    #+#             */
/*   Updated: 2023/07/05 16:52:46 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	count;
	int	check_word;

	count = 0;
	check_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			check_word = 0;
		}
		else if (check_word == 0)
		{
			check_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	*ft_get_word(char const *s, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;

	strings = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strings || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			strings[i] = ft_get_word(s, c);
			if (!strings[i])
				return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	strings[i] = NULL;
	return (strings);
}
