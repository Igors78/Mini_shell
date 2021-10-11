/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:01:10 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/07 16:01:53 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 42

// "r" for leftover remainder (static array of strings)

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

int	pre_check(int fd, char **line, char **buf, char **r)
{
	if (fd < 0 || fd > 1024 || !line || BUFFER_SIZE < 1
		|| read(fd, NULL, 0) < 0)
		return (-1);
	if (r[fd] == NULL)
		r[fd] = ft_strnew(0);
	if (NULL == r[fd])
		return (-1);
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == *buf)
		return (-1);
	return (0);
}

int	remain(int fd, int i, char **line, char **r)
{
	char	*p_n;
	char	*tmp;

	p_n = ft_strchr(r[fd], '\n');
	if (p_n)
	{
		tmp = r[fd];
		*line = ft_substr(r[fd], 0, (p_n - r[fd]));
		r[fd] = ft_strdup(r[fd] + (p_n - r[fd] + 1));
		ft_memdel((void **)&tmp);
		return (1);
	}
	else if (i == 0 && (!r[fd] || r[fd][0] == '\0'))
	{
		*line = ft_strnew(0);
		ft_memdel((void **)&r[fd]);
		return (0);
	}
	else
	{
		*line = ft_strdup(r[fd]);
		ft_memdel((void **)&r[fd]);
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*r[1024];
	char		*buf;
	char		*tmp;
	int			i;

	if (pre_check(fd, &*line, &buf, &*r) < 0)
		return (-1);
	tmp = NULL;
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		if (buf[0] != '\0')
		{
			tmp = ft_strjoin(r[fd], buf);
			ft_memdel((void **)&r[fd]);
			r[fd] = tmp;
		}
		if (ft_strchr(r[fd], '\n'))
			break ;
	}
	free(buf);
	return (remain(fd, i, &*line, &*r));
}
