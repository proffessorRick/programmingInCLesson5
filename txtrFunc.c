#include "common.h"
#include "main.h"
#include "txtrFunc.h"

SDL_Texture *load_texture(char *filename) {
  SDL_Texture *txtr;
  txtr = IMG_LoadTexture(renderer, filename);
  return txtr;
}

void blit(SDL_Texture *txtr, int x, int y, int center) {
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;

  SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);

  // If center != 0, render texture with its center on (x,y), NOT
  // with its top-left corner...
  if (center) {
    dest.x -= dest.w / 2;
    dest.y -= dest.h / 2;
  }

  SDL_RenderCopy(renderer, txtr, NULL, &dest);
}

void blit_angled(SDL_Texture *txtr, int x, int y, float angle) {
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;

  SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);

  // Textures that are rotated MUST ALWAYS be rendered with their
  // center at (x, y) to have a symmetrical center of rotation:
  dest.x -= (dest.w / 2);
  dest.y -= (dest.h / 2);

  // Look up what this function does. What do these rectangles
  // mean? Why is the source rectangle NULL? What are acceptable
  // values for the `angle' parameter?
  SDL_RenderCopyEx(renderer, txtr, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
}

