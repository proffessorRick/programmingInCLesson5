///////////////////////////////////////////////////////////////////////////////////////////////////////
//// INCLUDE OTHER FILES //////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "common.h"
#include "main.h"
#include "inputFunc.h"
#include "charFunc.h"
#include "mathFunc.h"
#include "txtrFunc.h"

// Make A Struct Array For Bullets //
struct _bullet_ bullets[BULLET_COUNT];
int bulletCounter = 0;

// Just Some Global Stuff //
int moveX = 0;
int moveY = 0;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;


int main(int argc, char *argv[]) {
  // All Security Checks //
  unsigned int window_flags = 0;
  unsigned int renderer_flags = SDL_RENDERER_ACCELERATED;
  
  if (SDL_Init(SDL_INIT_VIDEO) < 0) exit(1);
  window = SDL_CreateWindow("Blorp is going to F U UP!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);
  if (window == NULL) exit(1);	
  renderer = SDL_CreateRenderer(window, -1, renderer_flags);
  if (renderer == NULL) exit(1);	
 
  // Make Sure We Don't Get Some Stupid Warning That We Haven't Used Them // 
  (void)argc;
  (void)argv;

  // Make Sure It Can Alway Randomize //
  srand((uint8_t)time(0));

  // Make Both Player And NPC //
  player blorp 	= {(SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), 0.0f, 0.0f, UP, UP, UP, UP, 0.0, NULL, NULL, 0, 0, 0, 0};
  npc	 zombie = {0, 0, NULL, 0, 0.0};
 
  //  
  zombie.x = rand() % SCREEN_WIDTH;
  zombie.y = rand() % SCREEN_HEIGHT;

  // Load All Textures //
  IMG_Init(IMG_INIT_PNG);
  mouse mousepointer;
  mousepointer.txtr_reticle = load_texture("gfx/reticle.png");
  blorp.txtr_body = load_texture("gfx/idlebody/survivor-idle_handgun_0.png");
  blorp.txtr_feet = load_texture("gfx/idlefeet/survivor-idle_0.png");

  // No Visible Cursor For Us //
  SDL_ShowCursor(0);
   
  // Comment It Equivlant In While For More Giggles // 
  SDL_SetRenderDrawColor(renderer, 120, 144, 156, 255);
  SDL_RenderClear(renderer);

  while (1) {
    SDL_SetRenderDrawColor(renderer, 120, 144, 156, 255);
    SDL_RenderClear(renderer);
		
    // # Sensor Reading #
    // Also takes the mouse movement into account:
    process_input(&blorp, &mousepointer);
	
    // If A Bullet Has Been Made Run The Muzzleflash //
    if (blorp.gunstate) createMuzzleFlash(&blorp);
    
    travelBullet();

    // # Applying Game Logic #
    // Also takes the mouse movement into account:
    update_player(&blorp, &mousepointer);

    // # Actuator Output Buffering #
    // Also takes texture rotation into account:
    showPlayerState(&blorp);
    showNpcState(&blorp, &zombie);
    
    blit_angled(zombie.txtr_npc, zombie.x, zombie.y, zombie.angle);
    blit_angled(blorp.txtr_feet, blorp.x, blorp.y, blorp.angle);
    blit_angled(blorp.txtr_body, blorp.x, blorp.y, blorp.angle);

    // New: Redraw mouse pointer centered on the mouse coordinates:
    blit(mousepointer.txtr_reticle, mousepointer.x, mousepointer.y, 1);
  
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
  }

  return 0;
}

void makeBullet(player *tha_playa) {
  if (bulletCounter == BULLET_COUNT) bulletCounter = 0;
  bulletCounter++;
  
  bullet bulletPointer;
  
  bulletPointer.bulletCount = bulletCounter;
  bulletPointer.angle = ((tha_playa->angle / 180) * PI);
 
  double compX = (80 * cos(bulletPointer.angle)) - (56 * sin(bulletPointer.angle));
  double compY = (80 * sin(bulletPointer.angle)) + (56 * cos(bulletPointer.angle));

  bulletPointer.x = tha_playa->x + (int)compX;
  bulletPointer.y = tha_playa->y + (int)compY;
  bulletPointer.txtr_bullet = load_texture("gfx/bullet20x5.png");
  bulletPointer.angle = tha_playa->angle;

  bullets[bulletPointer.bulletCount] = bulletPointer;
  tha_playa->gunstate = 1;
}

void travelBullet() {
  for (int a = 0; a < BULLET_COUNT; a++) {
    struct _bullet_ shotBullet = bullets[a];

    shotBullet.x += cos((shotBullet.angle/180)*PI) * BULLET_SPEED;
    shotBullet.y += sin((shotBullet.angle/180)*PI) * BULLET_SPEED;

    bullets[shotBullet.bulletCount] = shotBullet;
  
    blit_angled(shotBullet.txtr_bullet, (int)shotBullet.x, (int)shotBullet.y, (float)shotBullet.angle);
  }
}

void createMuzzleFlash(player *tha_playa) {
  // Calculate Angle //
  double angle = ((tha_playa->angle / 180) * PI);
  
  // Calculate Location Off Muzzle Flash //
  double muzzleX = (130 * cos(angle)) - (56 * sin(angle)) + tha_playa->x;
  double muzzleY = (130 * sin(angle)) + (56 * cos(angle)) + tha_playa->y;

  // Load The Image For Muzzle Flash //
  SDL_Texture *muzzleFlash = load_texture("gfx/shoot/muzzle_flash_01.png");

  // Remove Black Background From Texture //
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);
  SDL_SetTextureBlendMode(muzzleFlash, SDL_BLENDMODE_ADD);
  SDL_SetTextureColorMod(muzzleFlash, 255, 255, 255);
  SDL_SetTextureAlphaMod(muzzleFlash, 255);

  // Load The Texture Into The Screen //
  blit_angled(muzzleFlash, (int)muzzleX, (int)muzzleY, tha_playa->angle);
  tha_playa->gunstate = 0;

  for (int delay = 0; delay < 1000; delay++);
}
