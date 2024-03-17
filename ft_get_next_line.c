/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:12:26 by sgardier          #+#    #+#             */
/*   Updated: 2024/03/17 16:56:52 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_get_next_line_update(char buff[BUFFER_SIZE + 1],
		size_t read_length, char **next_line, char **new_line_pos)
{
	char	*temp;

	buff[read_length] = '\0';
	temp = *next_line;
	*next_line = (char *)malloc(sizeof(char) * (ft_strlen(*next_line)
				+ read_length + 1));
	if (*next_line == NULL)
	{
		free(temp);
		return (-1);
	}
	ft_memcpy(*next_line, temp, ft_strlen(temp));
	ft_memcpy(*next_line + ft_strlen(temp), buff, read_length);
	(*next_line)[ft_strlen(temp) + read_length] = '\0';
	free(temp);
	*new_line_pos = ft_strchr(*next_line, '\n');
	return (0);
}

static char	*ft_get_next_line_loop(int fd, char **next_line,
		char **new_line_pos)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	read_length;

	while (*new_line_pos == NULL)
	{
		read_length = read(fd, buff, BUFFER_SIZE);
		if (read_length < 0)
		{
			free(*next_line);
			return (NULL);
		}
		else if (read_length == 0)
		{
			if (ft_strlen(*next_line) == 0)
			{
				free(*next_line);
				return (NULL);
			}
			return (*next_line);
		}
		if (ft_get_next_line_update(buff, read_length, next_line,
				new_line_pos) == -1)
			return (NULL);
	}
	return (*next_line);
}

static int	ft_get_next_line_init(int fd, char residue[BUFFER_SIZE + 1],
		char **next_line, char **new_line_pos)
{
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_memset(residue, '\0', BUFFER_SIZE + 1);
		return (-1);
	}
	*next_line = ft_strdup(residue);
	if (!(*next_line))
		return (-1);
	*new_line_pos = ft_strchr(*next_line, '\n');
	ft_memset(residue, '\0', BUFFER_SIZE + 1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	residue[BUFFER_SIZE + 1];
	char		*next_line;
	char		*new_line_pos;
	char		*next_line_cpy;

	if (ft_get_next_line_init(fd, residue, &next_line, &new_line_pos))
		return (NULL);
	next_line = ft_get_next_line_loop(fd, &next_line, &new_line_pos);
	if (new_line_pos != NULL)
	{
		ft_strlcpy(residue, new_line_pos + 1, BUFFER_SIZE + 1);
		next_line_cpy = next_line;
		*(new_line_pos + 1) = '\0';
		next_line = ft_strdup(next_line);
		free(next_line_cpy);
	}
	return (next_line);
}
