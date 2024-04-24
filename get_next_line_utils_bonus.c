/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:00:59 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/23 13:01:08 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char		*duplicate;
	size_t		i;
	size_t		s_len;

	i = 0;
	s_len = ft_strlen(s1);
	duplicate = (char *)malloc((s_len + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	while (s1[i])
	{
		duplicate[i] = s1[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char		*new_string;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	new_string = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_string[i + j] = s2[j];
		j++;
	}
	free(s1);
	new_string[i + j] = '\0';
	return (new_string);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*string;
	size_t		i;

	if (!s || !len || start >= ft_strlen(s))
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	string = (char *)malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = s[i + start];
		i++;
	}
	string[i] = '\0';
	return (string);
}
