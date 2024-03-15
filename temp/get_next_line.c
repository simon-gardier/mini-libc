/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:12:26 by sgardier          #+#    #+#             */
/*   Updated: 2024/03/15 18:28:39 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


//REMOVE
#include <stdlib.h>
char	*ft_strdup(const char *s1)
{
	char	*s1_dup;
	size_t	i;
	size_t	s1_length;

	s1_length = ft_strlen(s1);
	s1_dup = malloc(sizeof(char) * (s1_length + 1));
	if (!s1_dup)
		return (NULL);
	i = 0;
	while (i < s1_length)
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	return (s1_dup);
}
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*pos;

	i = 0;
	pos = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			pos = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		pos = (char *)(s + i);
	return (pos);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*strjoined;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strjoined = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strjoined)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		strjoined[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		strjoined[len_s1 + i] = s2[i];
	strjoined[len_s1 + len_s2] = '\0';
	return (strjoined);
}
void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	i;

	if (!destination && !source)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char *)destination)[i] = ((unsigned char *)source)[i];
		i++;
	}
	return (destination);
}
size_t	ft_strlen(char const *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}
//END REMOVE

static char	*ft_augment_next_line(char const *next_line, char const *buffer,
		ssize_t buffer_len)
{
	char	*strjoined;

	if (!next_line || !buffer)
		return (NULL);
	strjoined = (char *)malloc(sizeof(char) * (ft_strlen(next_line) + buffer_len
				+ 1));
	if (!strjoined)
		return (NULL);
	ft_memcpy(strjoined, next_line, ft_strlen(next_line));
	ft_memcpy(strjoined + ft_strlen(next_line), buffer, buffer_len);
	strjoined[ft_strlen(next_line) + buffer_len] = '\0';
	return (strjoined);
}

static int	ft_get_next_line_update(char buff[BUFFER_SIZE + 1],
		ssize_t read_length, char **next_line, ssize_t *newline_pos)
{
	char	*temp;

	buff[read_length] = '\0';
	temp = (*next_line);
	(*next_line) = ft_augment_next_line((*next_line), buff, read_length);
	free(temp);
	if (!(*next_line))
		return (-1);
	*newline_pos = ft_newline_position((*next_line));
	return (0);
}

static char	*ft_get_next_line_loop(int fd, char **next_line,
		ssize_t *newline_pos)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	read_length;

	while (*newline_pos == -1)
	{
		read_length = read(fd, buff, BUFFER_SIZE);
		if (read_length < 0)
		{
			free((*next_line));
			return (NULL);
		}
		if (read_length == 0)
		{
			if (ft_strlen((*next_line)) == 0)
			{
				free((*next_line));
				return (NULL);
			}
			return (*next_line);
		}
		if (ft_get_next_line_update(buff, read_length, next_line,
				newline_pos) == -1)
			return (NULL);
	}
	return (*next_line);
}

int	ft_get_next_line_init(int fd, char residue[BUFFER_SIZE + 1],
		char **next_line, ssize_t *newline_pos)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX || read(fd, 0,
			0) < 0)
	{
		ft_memset(residue, '\0', BUFFER_SIZE + 1);
		return (-1);
	}
	*next_line = ft_strdup(residue);
	if (!(*next_line))
		return (-1);
	*newline_pos = ft_newline_position(*next_line);
	ft_memset(residue, '\0', BUFFER_SIZE + 1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	residue[BUFFER_SIZE + 1];
	char		*next_line;
	ssize_t		newline_pos;
	char		*next_line_cpy;

	if (ft_get_next_line_init(fd, residue, &next_line, &newline_pos) == -1)
		return (NULL);
	next_line = ft_get_next_line_loop(fd, &next_line, &newline_pos);
	if (newline_pos != -1)
	{
		ft_memcpy(residue, &next_line[newline_pos + 1],
			ft_strlen(&next_line[newline_pos + 1]));
		residue[ft_strlen(&next_line[newline_pos + 1])] = '\0';
		next_line[newline_pos + 1] = '\0';
		next_line_cpy = ft_strdup(next_line);
		free(next_line);
		next_line = next_line_cpy;
	}
	return (next_line);
}
