/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:46:35 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/07 19:59:00 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_tile(t_data *d, int y, int x, int on_exit)
{
	if (on_exit)
		d->map[y][x] = d->content.exit;
	else
		d->map[y][x] = d->content.space;
}

void	handle_exit(t_data *d, int y, int x, int on_exit)
{
	if (chk_collect(d) == 0)
	{
		d->count++;
		ft_printf("Félicitations ! Gagné en %d coups !\n", d->count);
		end(d);
		return ;
	}
	update_tile(d, y, x, on_exit);
}

void	move_player(t_data *d, int dx, int dy)
{
	int		x;
	int		y;
	char	next;
	int		on_exit;

	x = d->pos.x / d->img.height;
	y = d->pos.y / d->img.width;
	next = d->map[y + dy][x + dx];
	on_exit = (d->map[y][x] == d->content.exit);
	if (next == d->content.wall)
		return ;
	if (next == d->content.exit)
		handle_exit(d, y, x, on_exit);
	else
	{
		update_tile(d, y, x, on_exit);
		d->map[y + dy][x + dx] = d->content.player;
	}
	d->pos.x += dx * d->img.height;
	d->pos.y += dy * d->img.width;
	d->count++;
	ft_printf("count: %d\n", d->count);
}
