/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:55:38 by dlamark-          #+#    #+#             */
/*   Updated: 2023/08/20 17:27:10 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	memory = read_line_break(fd, memory);
	if (!memory)
		return (NULL);
	line = ft_get_line(memory);
	memory = store_memory(memory);
	return (line);
}

char	*read_line_break(int fd, char *memory)
{
	char	*buffer;
	int		byte_read;

	if (!memory)
		memory = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		memory = join_and_free(memory, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (memory);
}

char	*join_and_free(char *memory, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(memory, buffer);
	free(memory);
	return (temp);
}

char	*ft_get_line(char *memory)
{
	char	*line;
	int		i;

	i = 0;
	if (!memory[i])
		return (NULL);
	while (memory[i] && memory[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] && memory[i] == '\n')
		line[i++] = '\n';
	line[i++] = '\0';
	return (line);
}

char	*store_memory(char *memory)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i])
	{
		free(memory);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(memory) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (memory[i])
		line[j++] = memory[i++];
	free(memory);
	return (line);
}
