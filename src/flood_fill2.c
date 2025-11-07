/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:30:18 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/07 19:59:39 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(t_data *data)
{
	char	**copy;
	int		i;

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

int	print_err(int id)
{
	if (id == 1)
	{
		ft_error("Error\nCollectible/Exit are unreachable.\n");
		exit (-1);
	}
	else if (id == 2)
	{
		ft_error("Error\n No Player Found\n");
		return (0);
	}
	return (0);
}
