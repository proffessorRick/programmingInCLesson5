#ifndef INPUTFUNC_H
#define INPUTFUNC_H

void process_input(player *tha_playa, mouse *tha_mouse);	
void handle_key(SDL_KeyboardEvent *keyevent, keystate updown, player *tha_playa);
void proper_shutdown(void);

#endif
