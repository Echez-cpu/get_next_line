/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:23:04 by pokpalae          #+#    #+#             */
/*   Updated: 2023/12/20 14:25:49 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char const *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return ((void *)0);
}

size_t	ft_strlen(char const *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char const *s1)
{
	size_t	i;
	size_t	len;
	char	*dub;
	char	*dup_ptr;

	len = 0;
	while (s1[len] != '\0')
		len++;
	dub = (char *)malloc((len + 1) * sizeof(char));
	dup_ptr = dub;
	if (dub == ((void *)0))
		return ((void *)0);
	i = 0;
	while (s1[i] != '\0')
	{
		*dup_ptr = s1[i];
		i++;
		dup_ptr++;
	}
	*dup_ptr = '\0';
	return (dub);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s3;
	char	*p3;
	char	*p1;

	s3 = malloc(sizeof(*s3) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	p3 = s3;
	p1 = s1;
	while (*p1)
		*p3++ = *p1++;
	while (*s2)
		*p3++ = *s2++;
	*p3 = '\0';
	free(s1);
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*substring;

	if (s == ((void *)0))
		return ((void *)0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[len] = '\0';
	return (substring);
}
