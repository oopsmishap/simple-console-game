#pragma once
#include <stdbool.h>

#define WORLD_SIZE_X		10
#define WORLD_SIZE_Y		10

#define EXIT_X				9
#define EXIT_Y				9

// 0 = Black       8 = Gray
// 1 = Blue        9 = Light Blue
// 2 = Green       A = Light Green
// 3 = Aqua        B = Light Aqua
// 4 = Red         C = Light Red
// 5 = Purple      D = Light Purple
// 6 = Yellow      E = Light Yellow
// 7 = White       F = Bright White

#define COLOR_GRASS			0x22
#define COLOR_FIRE			0x44
#define COLOR_WALL			0x88
#define COLOR_EXIT			0xAA
#define COLOR_PLAYER		0x13
#define COLOR_WIN			0xA1
#define COLOR_LOSE			0xC1
#define COLOR_HP_BAR		0xC7

#define TILE_GRASS '.'
#define TILE_WALL  'O'
#define TILE_FIRE  'f'
#define TILE_EXIT  'E'

extern char world[ WORLD_SIZE_Y ][ WORLD_SIZE_X ];

bool is_wall( int x, int y );
bool is_fire( int x, int y );
bool is_valid_tile( int x, int y );