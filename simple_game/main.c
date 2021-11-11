/*
A world exists of 10 x 10 locations.  
There are 4 types of object in the world: grass, wall, fire, exit.  
Each location can be one of these.

Create a character that you can move onto any location using simple U,D,L,R keystroke/menu inputs.
Note:
	They cannot walk through walls.
	They can walk through fire – but that removes 10 from their original health of 100.
	The program should run until the character either dies (health=0) or they hit the exit location.
	
	Start the character away from the exit.  
	
	How you design the 10x10 world is your imagination.
*/

#include "console_funcs.h"
#include "world.h"
#include "player.h"
#include "draw.h"

#define KEY_UP		72
#define KEY_DOWN	80
#define KEY_LEFT	75
#define KEY_RIGHT	77

void game_win()
{
	gotoxy( 1, 4 );
	set_colour( COLOR_WIN );
	_cprintf( "You Win!" );
}

void game_lost()
{
	gotoxy( 0, 4 );
	set_colour( COLOR_LOSE );
	_cprintf( "You Lose!" );
}

void handle_input( player_t* player, char key )
{
	switch( key )
	{
	case KEY_UP:
		move_player( player, 0, -1 );
		break;
	case KEY_DOWN:
		move_player( player, 0, +1 );
		break;
	case KEY_LEFT:
		move_player( player, -1, 0 );
		break;
	case KEY_RIGHT:
		move_player( player, +1, 0 );
		break;
	default:
		break;
	}
}

void game_loop( player_t* player )
{
	while( !is_player_at_exit( player ) && !is_player_dead( player ) )
	{
		if( _kbhit() )
			handle_input( player, _getch() );

		draw_player( player );
		draw_health( player );
	}

	while( !_kbhit() )
	{
		if( is_player_at_exit( player ) )
		{
			game_win();
		}
		else if( is_player_dead( player ) )
		{
			game_lost();
		}
	}

	gotoxy( 0, WORLD_SIZE_Y + 1 );
}

void game_init()
{
	setup_console();

	player_t player = 
	{ 
		.x		= PLAYER_X_START,
		.y		= PLAYER_Y_START,
		.prev_x = PLAYER_X_START,
		.prev_y = PLAYER_Y_START,
		.hp		= PLAYER_HP_START
	};

	for( int x = 0; x < WORLD_SIZE_X; x++ )
	{
		for( int y = 0; y < WORLD_SIZE_Y; y++ )
		{
			draw_world_tile( x, y );
		}
	}

	game_loop( &player );
}

int main()
{
	game_init();
	
	return 0;
}