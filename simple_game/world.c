#include "world.h"

/*
. = grass
O = wall
f = fire
E = exit
*/

char world[ WORLD_SIZE_Y ][ WORLD_SIZE_X ] =
{
	{ '.','.','.','O','.','.','.','f','f','.' },
	{ 'O','O','.','O','.','.','.','O','O','.' },
	{ '.','.','.','O','.','O','.','O','O','.' },
	{ '.','O','O','O','.','O','.','f','f','.' },
	{ '.','.','.','O','.','O','.','f','f','.' },
	{ 'O','.','O','O','.','O','.','f','f','.' },
	{ '.','f','O','O','.','O','.','f','f','.' },
	{ '.','f','f','f','f','O','f','O','f','O' },
	{ '.','O','.','O','f','f','f','O','f','.' },
	{ '.','.','.','O','f','f','f','O','O','E' },
};

bool is_wall( int x, int y )
{
	if( x < 0 && x > WORLD_SIZE_X )
		return false;

	if( y < 0 && y > WORLD_SIZE_Y )
		return false;

	if( world[ y ][ x ] == TILE_WALL )
		return true;

	return false;
}

bool is_fire( int x, int y )
{
	if( x < 0 && x > WORLD_SIZE_X )
		return false;

	if( y < 0 && y > WORLD_SIZE_Y )
		return false;

	if( world[ y ][ x ] == TILE_FIRE )
		return true;

	return false;
}

bool is_valid_tile( int x, int y )
{
	if( 0 <= x && x <= ( WORLD_SIZE_X - 1 ) &&
		0 <= y && y <= ( WORLD_SIZE_Y - 1 ) )
	{
		return true;
	}

	return false;
}