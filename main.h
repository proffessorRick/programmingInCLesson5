#ifndef MAIN_H
#define MAIN_H

// Make This extern So We Can Use It In inputFunc //
extern SDL_Window *window;
extern SDL_Renderer *renderer;

// Make This extern So We Can Use It In charFunc //
extern int moveX;
extern int moveY;


void makeBullet(player *tha_playa);
void travelBullet();
void createMuzzleFlash(player *tha_playa);
SDL_Texture *load_texture(char *filename);
void blit(SDL_Texture *txtr, int x, int y, int center);
void blit_angled(SDL_Texture *txtr, int x, int y, float angle);

#endif
