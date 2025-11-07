/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:14:27 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/07 21:14:45 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_error("Error\nThis program takes 1 argument .ber\n");
		return (1);
	}
	set_content(&(data.content));
	data.map = map_core(argv, &data);
	data.count = 0;
	data.mlx_ptr = mlx_init();
	if (!data.map)
		end(&data);
	check_path_valid(&data);
	set_img(&data);
	core_render(&data);
	return (0);
}
