/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:06:52 by mgourlai          #+#    #+#             */
/*   Updated: 2023/05/03 19:06:55 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "countlines.h"

// this function takes the temp string and keeps whats after \n AKA le 20%
char	*saverestofcount(char *temp)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * ((ft_strlen(temp) - i) + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (temp[i])
		rest[j++] = temp[i++];
	rest[j] = '\0';
	free(temp);
	return (rest);
}

// counts only line from start to \n AKA le 80%
void	counter(char *temp, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	if (!temp[i])
		return ;
	while (temp[i] && temp[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return ;
	i = 0;
	while (temp[i++] && temp[i] != '\n')
	{
		line[i] = temp[i];
	}
	if (temp[i] == '\n')
	{
		line[i] = temp[i];
		i++;
		game->info_map.linecount++;
	}
	line[i] = '\0';
	free (line);
	return ;
}

// cuts until \n with too many characters to trim later AKA le 100%
char	*cuttext(char *temp, int fd)
{
	char	*buffer;
	int		index;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	index = 1;
	while (!ft_strchr(temp, '\n') && index > 0)
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[index] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

// main function
void	startcount(int fd, t_game *game)
{
	static char	*temp[260];

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return ;
	temp[fd] = cuttext(temp[fd], fd);
	if (!temp[fd])
		return ;
	while (1)
	{
		temp[fd] = cuttext(temp[fd], fd);
		counter(temp[fd], game);
		temp[fd] = saverestofcount(temp[fd]);
		if (temp[fd] == NULL)
			break ;
	}
}
