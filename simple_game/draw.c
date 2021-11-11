#include "draw.h"
#include "world.h"

void draw_world_tile( int x, int y )
{
	char tile_type = world[ y ][ x ];

	switch( tile_type )
	{
	case TILE_GRASS:
		draw_tile( x, y, COLOR_GRASS );
		break;
	case TILE_WALL:
		draw_tile( x, y, COLOR_WALL );
		break;
	case TILE_FIRE:
		draw_tile( x, y, COLOR_FIRE );
		break;
	case TILE_EXIT:
		draw_tile( x, y, COLOR_EXIT );
		break;
	default:
		break;
	}
}

void draw_player( player_t* player )
{
	draw_world_tile( player->prev_x, player->prev_y );
	set_colour( COLOR_PLAYER );
	gotoxy( player->x, player->y );
	_cprintf( "Ø" );
}

void draw_health( player_t* player )
{
	set_colour( COLOR_HP_BAR );
	gotoxy( 0, WORLD_SIZE_Y );
	_cprintf( "HP: %6d", player->hp );
}

void draw_tile( int x, int y, short color )
{
	set_colour( color );
	gotoxy( x, y );
	_cprintf( " " );
}