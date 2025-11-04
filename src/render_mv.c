#include "../so_long.h"

static void	move_player(t_data *d, int dx, int dy)
{
	int	x = d->pos.x / d->img.height;
	int	y = d->pos.y / d->img.width;
	char	next = d->map[y + dy][x + dx];
	int		on_exit = (d->map[y][x] == d->content.exit);

	if (next == d->content.wall)
		return;
	if (next == d->content.exit)
	{
		if (chk_collect(d) == 0)
		{
			printf("Félicitations ! Gagné en %d coups !\n", ++d->count);
			end(d);
		}
		else
			d->map[y][x] = on_exit ? d->content.exit : d->content.space;
	}
	else
	{
		d->map[y][x] = on_exit ? d->content.exit : d->content.space;
		d->map[y + dy][x + dx] = d->content.player;
	}
	d->pos.x += dx * d->img.height;
	d->pos.y += dy * d->img.width;
	printf("count: %d\n", ++d->count);
}

void	render_top(t_data *d){move_player(d,0,-1);}
void	render_right(t_data *d){move_player(d,1,0);}
void	render_left(t_data *d){move_player(d,-1,0);}
void	render_down(t_data *d){move_player(d,0,1);}
