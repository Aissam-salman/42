/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:44:44 by fardeau           #+#    #+#             */
/*   Updated: 2026/03/17 17:25:36 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// FUNCTION USED TO DRAW ONE MINIMAP TILE AT THE GIVEN MAP POSITION
void	ft_tile_draw(t_tile *tile, int map_x, int map_y)
{
	mlx_put_image_to_window(DATA(tile->minimap)->mlx,
		DATA(tile->minimap)->win,
		tile->tile_img.img,
		tile->minimap->offset_x + (map_x * TILE_SIZE),
		tile->minimap->offset_y + (map_y * TILE_SIZE));
}

// FUNCTION USED TO DRAW THE WHOLE MINIMAP FROM THE MAP GRID
void	ft_minimap_draw(t_minimap *minimap)
{
	int	y;
	int	x;
	char	*row;

	y = -1;
	while (++y < minimap->map->height)
	{
		row = minimap->map->map[y];
		x = -1;
		// Iterate on the real row length to avoid reading past shorter rows.
		while (row[++x] && row[x] != '\n')
		{
			if (ft_ischarset(row[x], "0NSEW"))
				ft_tile_draw(&minimap->tiles[EMPTY], x, y);
			else if (row[x] == '1')
				ft_tile_draw(&minimap->tiles[WALL], x, y);
		}
	}
}

// FUNCTION USED TO DRAW THE PLAYER MARKER AT THE RIGHT MINIMAP POSITION
void	ft_char_draw(t_player *player)
{
	int	screen_x;
	int	screen_y;

	screen_x = DATA(player)->map.minimap.offset_x
		+ (int)(player->pos_x * TILE_SIZE) - (player->char_img.width / 2);
	screen_y = DATA(player)->map.minimap.offset_y
		+ (int)(player->pos_y * TILE_SIZE) - (player->char_img.height / 2);
	mlx_put_image_to_window(DATA(player)->mlx,
		DATA(player)->win,
		player->char_img.img,
		screen_x,
		screen_y);
}

void	ft_orient_draw(t_player *player)
{
	int	screen_x;
	int	screen_y;

	// test_view is a tiny marker in front of the player direction vector.
	screen_x = DATA(player)->map.minimap.offset_x
		+ (int)((player->pos_x + player->dir_x) * TILE_SIZE)
		- (player->test_view.width / 2);
	screen_y = DATA(player)->map.minimap.offset_y
		+ (int)((player->pos_y + player->dir_y) * TILE_SIZE)
		- (player->test_view.height / 2);
	mlx_put_image_to_window(DATA(player)->mlx,
		DATA(player)->win,
		player->test_view.img,
		screen_x,
		screen_y);
}

// FUNCTION USED TO RENDER THE MINIMAP AND THE PLAYER MARKER EACH FRAME
int	ft_map_render(void *cub)
{
	t_cub	*data;

	data = (t_cub *)cub;
	ft_minimap_draw(&data->map.minimap);
	ft_char_draw(&data->player);
	ft_orient_draw(&data->player);
	return (SUCCESS);
}