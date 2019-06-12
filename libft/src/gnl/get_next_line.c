/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:04:33 by fhong             #+#    #+#             */
/*   Updated: 2019/05/28 23:12:42 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>

char	*my_strsearch(char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
		if (str[i++] == c)
		{
			tmp = ft_strnew(i - 1);
			tmp = ft_strncpy(tmp, str, i - 1);
			free(str);
			return (tmp);
		}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf[1024];
	int			ret;
	char		*tmp;

	if (fd < 0 || read(fd, buf[fd], 0) < 0 || line == NULL)
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(GNL_BUFF_SIZE);
	*line = ft_strdup(buf[fd]);
	while (!ft_strchr(*line, '\n') && (ret = read(fd, buf[fd], GNL_BUFF_SIZE)))
	{
		buf[fd][ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buf[fd]);
		ft_bzero(buf[fd], ft_strlen(buf[fd]));
		free(tmp);
	}
	if (ft_strlen(*line) == 0)
		return (0);
	if ((tmp = ft_strchr(*line, '\n')))
		buf[fd] = ft_strcpy(buf[fd], (tmp + 1));
	else
		buf[fd] = NULL;
	*line = my_strsearch(*line, '\n');
	return (1);
}
