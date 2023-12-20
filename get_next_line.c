/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:54:15 by pokpalae          #+#    #+#             */
/*   Updated: 2023/12/20 13:59:29 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char **temp)
{
	char	*done;
	char	*update;

	update = *temp;
	while (*update != '\0' && *update != '\n')
		update++;
	if (*update == '\n')
		update++;
	done = ft_substr(*temp, 0, (size_t)(update - *temp));
	if (!done)
	{
		free(*temp);
		return (((void *)0));
	}
	update = ft_substr(update, 0, ft_strlen(update));
	free(*temp);
	*temp = update;
	return (done);
}

static char	*ft_read_me(char *temp, int fd, char *buf)
{
	ssize_t	r_or_err;

	r_or_err = 1;
	while (r_or_err && ft_strchr(temp, '\n') == ((void *)0))
	{
		r_or_err = read(fd, buf, BUFFER_SIZE);
		if (r_or_err == -1)
		{
			free(buf);
			free(temp);
			return ((void *)0);
		}
		buf[r_or_err] = '\0';
		temp = ft_strjoin(temp, buf);
		if (!temp)
		{
			free(buf);
			return ((void *)0);
		}
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 1)
		return ((void *)0);
	if (!temp)
		temp = ft_strdup("");
	if (!temp)
		return ((void *)0);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(temp);
		return ((void *)0);
	}
	temp = ft_read_me(temp, fd, buf);
	if (!temp)
		return ((void *)0);
	if (*temp == '\0')
	{
		free(temp);
		temp = ((void *)0);
		return ((void *)0);
	}
	return (next_line(&temp));
}
