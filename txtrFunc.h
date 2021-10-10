#ifndef TXTRFUNC_H
#define TXTRFUNC_H

SDL_Texture *load_texture(char *filename);
void blit(SDL_Texture *txtr, int x, int y, int center);
void blit_angled(SDL_Texture *txtr, int x, int y, float angle);

#endif
