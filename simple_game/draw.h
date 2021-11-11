#pragma once
#include "player.h"

void draw_world_tile( int x, int y );
void draw_player( player_t* player );
void draw_health( player_t* player );
void draw_tile( int x, int y, short color );