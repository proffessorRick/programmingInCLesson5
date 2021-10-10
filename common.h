#ifndef common_h
#define common_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>

#define SCREEN_WIDTH				1800
#define SCREEN_HEIGHT				1000
#define PI					3.14159265358979323846
#define PLAYER_MAX_SPEED			6.0f
#define PLAYER_DECELERATION			0.25f
#define BULLET_COUNT				15
#define BULLET_SPEED				35

typedef struct _mouse_ {
  int x;
  int y;
  SDL_Texture *txtr_reticle;
} mouse;

typedef struct _bullet_ {
  int bulletCount;
  double x;
  double y;
  SDL_Texture *txtr_bullet;
  double angle;
} bullet;

typedef enum _playerstate_ {
  IDLE = 0,
  WALKING = 1,
} playerstate;

typedef enum _firestate_ {
  SAFETY_FIRST = 0,
  SHOOT_FIRST  = 1,
} firestate;

typedef struct _player_ {
  int x;
  int y;
  float speed_x;
  float speed_y;
  int up;
  int down;
  int left;
  int right;
  float angle;
  SDL_Texture *txtr_body;
  SDL_Texture *txtr_feet;
  int counterIdle; 
  int counterMoving;

  playerstate state;
  firestate gunstate;
} player;

typedef struct _npc_ {
  int x;
  int y;
  SDL_Texture *txtr_npc;
  int counterIdle;
  float angle;
} npc;

typedef enum _keystate_ {
  UP = 0,
  DOWN = 1
} keystate;

#endif
