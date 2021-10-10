#ifndef main_h
#define main_h

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

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern int moveX;
extern int moveY;

void makeBullet(player *tha_playa);
void travelBullet();
void createMuzzleFlash(player *tha_playa);

SDL_Texture *load_texture(char *filename);

// This function has changed because texture rotation was added,
// which means drawing a texture centered on a coordinate is easier:
void blit(SDL_Texture *txtr, int x, int y, int center);
void blit_angled(SDL_Texture *txtr, int x, int y, float angle);

float get_angle(int x1, int y1, int x2, int y2, SDL_Texture *texture);

#endif
