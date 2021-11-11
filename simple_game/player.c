#include "player.h"
#include "world.h"

bool is_player_at_exit( player_t* player )
{
	if( player->x == EXIT_X && player->y == EXIT_Y )
	{
		return true;
	}
	return false;
}

bool is_player_dead( player_t* player )
{
	if( player->hp < 1 )
	{
		return true;
	}
	return false;
}

void move_player( player_t* player, int dir_x, int dir_y )
{
	if( is_valid_tile( player->x + dir_x, player->y + dir_y ) )
	{
		if( is_wall( player->x + dir_x, player->y + dir_y ) )
			return;

		if( is_fire( player->x + dir_x, player->y + dir_y ) )
			player->hp -= 10;

		player->prev_y = player->y;
		player->prev_x = player->x;

		player->x = player->x + dir_x;
		player->y = player->y + dir_y;
	}
}