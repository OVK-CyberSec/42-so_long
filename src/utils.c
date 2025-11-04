#include "../so_long.h"

int	is_wall_line(char *str)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

static void	flood_fill(t_data *data, t_pos curr, bool **visited)
{
	if (curr.x < 0 || curr.x >= data->width || curr.y < 0 || curr.y >= data->height)
		return;
	if (data->map[curr.y][curr.x] == '1' || visited[curr.y][curr.x])
		return;

	visited[curr.y][curr.x] = true;

	flood_fill(data, (t_pos){curr.x + 1, curr.y}, visited);
	flood_fill(data, (t_pos){curr.x - 1, curr.y}, visited);
	flood_fill(data, (t_pos){curr.x, curr.y + 1}, visited);
	flood_fill(data, (t_pos){curr.x, curr.y - 1}, visited);
}

static bool	check_accessibility(t_data *data, bool **visited)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if ((data->map[y][x] == 'C' || data->map[y][x] == 'E') && !visited[y][x])
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static void	free_visited(bool **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static t_pos	find_player_position(t_data *data)
{
	t_pos	player;
	int		y;
	int		x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'P')
			{
				player.x = x;
				player.y = y;
				return (player);
			}
			x++;
		}
		y++;
	}
	return ((t_pos){-1, -1});
}