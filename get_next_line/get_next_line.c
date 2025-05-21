/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:07:50 by mohifdi           #+#    #+#             */
/*   Updated: 2025/04/18 18:07:53 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(int fd, char *line)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!found_newline(line) && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = create_line(fd, line);
	if (!line)
		return (NULL);
	next_line = get_line(line);
	line = fetch_new_line(line);
	return (next_line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd;

// 	fd = open("file.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
// 		printf("line [%d] -> %s", i++, line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }