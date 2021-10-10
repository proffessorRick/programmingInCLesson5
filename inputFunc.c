#include "common.h"
#include "main.h"
#include "inputFunc.h"

void handle_key(SDL_KeyboardEvent *keyevent, keystate updown, player *tha_playa) {
  if (keyevent->repeat == 0) {
    int pressedW, pressedS, pressedA, pressedD;

    pressedW = keyevent->keysym.scancode == SDL_SCANCODE_W; 
    pressedS = keyevent->keysym.scancode == SDL_SCANCODE_S;
    pressedA = keyevent->keysym.scancode == SDL_SCANCODE_A;
    pressedD = keyevent->keysym.scancode == SDL_SCANCODE_D;

    if (pressedW || pressedS || pressedA || pressedD) tha_playa->state = 1;
    if (pressedW) tha_playa->up    = updown;      
    if (pressedS) tha_playa->down  = updown;		
    if (pressedA) tha_playa->left  = updown;
    if (pressedD) tha_playa->right = updown;		
  }
}

void process_input(player *tha_playa, mouse *tha_mouse) {	
  SDL_Event event;
	
  while (SDL_PollEvent(&event))	{		
    switch (event.type) {
      case SDL_QUIT:	
        proper_shutdown();
        exit(0);
	break;
      case SDL_MOUSEBUTTONDOWN:
	makeBullet(tha_playa);
	break;
      case SDL_KEYDOWN:	
	if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
	  proper_shutdown();					
	  exit(0);
	} else {
	  handle_key(&event.key, DOWN, tha_playa);
	}
	break;
      case SDL_KEYUP:
	handle_key(&event.key, UP, tha_playa);
	break;
      default:
	break;		
    }
  }

  SDL_GetMouseState(&tha_mouse->x, &tha_mouse->y);
}

void proper_shutdown(void) {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
