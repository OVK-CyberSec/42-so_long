#include "../so_long.h"


static char **copy_map(t_data *data)
{
	char **copy;
	int i;

	if (!data || !data->map)
		ft_error("Error\ndata->map NULL in copy_map");

	i = 0;
	while (data->map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		ft_error("Error\nmalloc copy_map");
	i = 0;
	while (data->map[i])
	{
		copy[i] = ft_strdup(data->map[i]);
		if (!copy[i])
			ft_error("Error\nstrdup copy_map");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static t_pos	find_player(char **map)
{
	t_pos	pos;
	int		y;
	int		x;

	pos.x = -1;
	pos.y = -1;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos);
}


static int	in_bounds(char **map, int x, int y)
{
	int	width;
	int	height;

	height = 0;
	while (map[height])
		height++;
	if (y < 0 || y >= height)
		return (0);
	width = ft_strlen(map[y]);
	if (x < 0 || x >= width)
		return (0);
	return (1);
}


static void	fill(char **map, int x, int y)
{
	if (!in_bounds(map, x, y))
		return;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	map[y][x] = 'V';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

static int	check_reachability(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_path_valid(t_data *data)
{
	char	**copy;
	t_pos	start;
	int		valid;
	int		y;

	copy = copy_map(data);
	if (!copy)
		return (0);
	start = find_player(copy);
	if (start.x == -1 || start.y == -1)
	{
		ft_error("Error\n No Player Found\n");
		return (0);
	}
	fill(copy, start.x, start.y);
	valid = check_reachability(copy);
	y = 0;
	while (copy[y])
		free(copy[y++]);
	free(copy);
	if (!valid)
    {
		ft_error("Error\nCollectible/Exit are unreachable.\n");
        exit (-1);
    }
    return (valid);
}
