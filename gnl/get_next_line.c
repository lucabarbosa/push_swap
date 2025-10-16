/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:51:16 by lbento            #+#    #+#             */
/*   Updated: 2025/10/16 01:32:43 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*read_line(int fd, char *remaining, char *buffer);
char	*save_file(char *line);

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (buffer);
		remaining = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = read_line(fd, remaining, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		remaining = NULL;
		return (NULL);
	}
	remaining = save_file(line);
	return (line);
}

char	*read_line(int fd, char *remaining, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(remaining);
			return (NULL);
		}
		else if (bytes_read == 0)
			return (remaining);
		buffer[bytes_read] = '\0';
		if (!remaining)
			remaining = ft_strdup_gnl("");
		temp = remaining;
		remaining = ft_strjoin_gnl(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr_gnl(buffer, '\n'))
			return (remaining);
	}
	return (remaining);
}

char	*save_file(char *line)
{
	char	*rest;
	size_t	i;
	size_t	size_line;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		return (NULL);
	}
	size_line = (ft_strlen_gnl(line) - i);
	rest = ft_substr_gnl(line, i + 1, size_line);
	if (*rest == '\0')
	{
		free(rest);
		rest = NULL;
	}
	line[i + 1] = '\0';
	return (rest);
}
