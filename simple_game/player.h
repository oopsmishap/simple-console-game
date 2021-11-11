#pragma once
#include <stdbool.h>

#define PLAYER_X_START 0
#define PLAYER_Y_START 0

#define PLAYER_HP_START 100

typedef struct
{
	int x;
	int y;
	int prev_x;
	int prev_y;
	int hp;
} player_t;

bool is_player_at_exit( player_t* player );
bool is_player_dead( player_t* player );

void move_player( player_t* player, int dir_x, int dir_y );