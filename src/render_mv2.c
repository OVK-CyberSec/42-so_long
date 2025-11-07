/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:54:14 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/07 19:54:17 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_top(t_data *data)
{
	move_player(data, 0, -1);
}

void	render_right(t_data *data)
{
	move_player(data, 1, 0);
}

void	render_left(t_data *data)
{
	move_player(data, -1, 0);
}

void	render_down(t_data *data)
{
	move_player(data, 0, 1);
}
