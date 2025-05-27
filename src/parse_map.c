
#include "../so_long.h"

char	*get_map(int fd)
{
	char	*line;
	char	*map;
	char 	*tmp;

	map = ft_strdup("");
	if (!map)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!line)
    		return (NULL);
		tmp = map;
		map = ft_strjoin(map, line);
		free(line);
		if (!map)
		{
			free(tmp);
			return (NULL);
		}
	}
	if (*map == '\0')
	{
		free(map);
		ft_error("Error\nEmpty or invalid map\n");
		return (NULL);
	}
	return (map);
}

void	*free_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

char	**parse_map(int fd, t_data *data)
{
	int		i;
	char	*map_str;

	map_str = get_map(fd);
	if (!map_str)
		return (NULL);
	data->map = ft_split(map_str, '\n');
	free(map_str);
	if (!data->map)
		return (NULL);
	check_content(data);
	if (!check_dimension(data->map))
		return (free_map(data));
	if (!check_line(data->map[0], data->content.wall))
		return (free_map(data));
	i = 1;
	while (data->map[i + 1])
	{
		if (!check_col(data->map[i], data->content.wall, data))
			return (free_map(data));
		if (!check_exeption(data->map[i], &(data->content)))
			return (free_map(data));
		i++;
	}
	data->height = i + 1;
	if (!check_line(data->map[i], data->content.wall))
		return (free_map(data));

	return (data->map);
}

char	**map_core(char **str, t_data *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (!ft_strnstr(str[1], ".ber", ft_strlen(str[1])))
    	return (ft_error("Error\nInvalid file extension\n"));

	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = parse_map(fd, data);
		else
			return (ft_error("Error\nFailed to open file\n"));
		if ((data->content.count_c == 0 || data->content.count_e != 1
				|| data->content.count_p != 1) && data->map != NULL)
		{
			free_map(data);
			return (ft_error(
					"Error\nNeed 1 Player/Exit and at least 1 Object\n"));
		}
	}
	return (data->map);
}
