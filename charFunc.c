///////////////////////////////////////////////////////////////////////////////////////////////////////
//// INCLUDE OTHER FILES //////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "common.h"
#include "main.h"
#include "mathFunc.h"
#include "charFunc.h"

void showNpcState(player *tha_playa, npc *tha_npc) {
  char *txtrIdleZombie[17] = {
    "gfx/monsters/skeleton-idle_0.png",  "gfx/monsters/skeleton-idle_1.png",
    "gfx/monsters/skeleton-idle_2.png",  "gfx/monsters/skeleton-idle_3.png",
    "gfx/monsters/skeleton-idle_4.png",  "gfx/monsters/skeleton-idle_5.png",
    "gfx/monsters/skeleton-idle_6.png",  "gfx/monsters/skeleton-idle_7.png",
    "gfx/monsters/skeleton-idle_8.png",  "gfx/monsters/skeleton-idle_9.png",
    "gfx/monsters/skeleton-idle_10.png", "gfx/monsters/skeleton-idle_11.png",
    "gfx/monsters/skeleton-idle_12.png", "gfx/monsters/skeleton-idle_13.png",
    "gfx/monsters/skeleton-idle_14.png", "gfx/monsters/skeleton-idle_15.png",
    "gfx/monsters/skeleton-idle_16.png",
  };

  if (tha_npc->counterIdle == 17) tha_npc->counterIdle = 0;

  tha_npc->txtr_npc 	= load_texture(txtrIdleZombie[tha_npc->counterIdle]);
  tha_npc->angle 	= get_angle(tha_npc->x, tha_npc->y, tha_playa->x, tha_playa->y, tha_npc->txtr_npc);
  tha_npc->counterIdle 	= tha_npc->counterIdle + 1;
}

void showPlayerState(player *tha_playa) {
  // Let's First Get The State Of The Player //
  playerstate state = tha_playa->state;

  switch(state) {
    case 0: // IDLE //
      if (tha_playa->counterIdle == 20) {
        tha_playa->counterIdle = 0;
      }

      char *texturesIdle[20] = {
	"gfx/idlebody/survivor-idle_handgun_0.png", "gfx/idlebody/survivor-idle_handgun_1.png",
	"gfx/idlebody/survivor-idle_handgun_2.png", "gfx/idlebody/survivor-idle_handgun_3.png",
	"gfx/idlebody/survivor-idle_handgun_4.png", "gfx/idlebody/survivor-idle_handgun_5.png",
	"gfx/idlebody/survivor-idle_handgun_6.png", "gfx/idlebody/survivor-idle_handgun_7.png",
	"gfx/idlebody/survivor-idle_handgun_8.png", "gfx/idlebody/survivor-idle_handgun_9.png",
	"gfx/idlebody/survivor-idle_handgun_10.png", "gfx/idlebody/survivor-idle_handgun_11.png",
	"gfx/idlebody/survivor-idle_handgun_12.png", "gfx/idlebody/survivor-idle_handgun_13.png",
	"gfx/idlebody/survivor-idle_handgun_14.png", "gfx/idlebody/survivor-idle_handgun_15.png",
	"gfx/idlebody/survivor-idle_handgun_16.png", "gfx/idlebody/survivor-idle_handgun_17.png",
	"gfx/idlebody/survivor-idle_handgun_18.png", "gfx/idlebody/survivor-idle_handgun_19.png"
      };

      tha_playa->txtr_body = load_texture(texturesIdle[tha_playa->counterIdle]);
      tha_playa->counterIdle = tha_playa->counterIdle + 1;
      break;
    case 1: // MOVING //
      if (tha_playa->counterMoving == 20) {
        tha_playa->counterMoving = 0;
      }

      char *texturesBody[20] = {
        "gfx/movebody/survivor-move_handgun_0.png", "gfx/movebody/survivor-move_handgun_1.png",
        "gfx/movebody/survivor-move_handgun_2.png", "gfx/movebody/survivor-move_handgun_3.png",
        "gfx/movebody/survivor-move_handgun_4.png", "gfx/movebody/survivor-move_handgun_5.png",
        "gfx/movebody/survivor-move_handgun_6.png", "gfx/movebody/survivor-move_handgun_7.png",
        "gfx/movebody/survivor-move_handgun_8.png", "gfx/movebody/survivor-move_handgun_9.png",
        "gfx/movebody/survivor-move_handgun_10.png", "gfx/movebody/survivor-move_handgun_11.png",
        "gfx/movebody/survivor-move_handgun_12.png", "gfx/movebody/survivor-move_handgun_13.png",
        "gfx/movebody/survivor-move_handgun_14.png", "gfx/movebody/survivor-move_handgun_15.png",
        "gfx/movebody/survivor-move_handgun_16.png", "gfx/movebody/survivor-move_handgun_17.png",
        "gfx/movebody/survivor-move_handgun_18.png", "gfx/movebody/survivor-move_handgun_19.png",
      };
    
      char *texturesFeet[20] = {
        "gfx/movefeet/survivor-walk_0.png", "gfx/movefeet/survivor-walk_1.png", 
        "gfx/movefeet/survivor-walk_2.png", "gfx/movefeet/survivor-walk_3.png", 
        "gfx/movefeet/survivor-walk_4.png", "gfx/movefeet/survivor-walk_5.png", 
        "gfx/movefeet/survivor-walk_6.png", "gfx/movefeet/survivor-walk_7.png", 
        "gfx/movefeet/survivor-walk_8.png", "gfx/movefeet/survivor-walk_9.png", 
        "gfx/movefeet/survivor-walk_10.png", "gfx/movefeet/survivor-walk_11.png", 
        "gfx/movefeet/survivor-walk_12.png", "gfx/movefeet/survivor-walk_13.png", 
        "gfx/movefeet/survivor-walk_14.png", "gfx/movefeet/survivor-walk_15.png", 
        "gfx/movefeet/survivor-walk_16.png", "gfx/movefeet/survivor-walk_17.png", 
        "gfx/movefeet/survivor-walk_18.png", "gfx/movefeet/survivor-walk_19.png", 
      };

      tha_playa->txtr_body = load_texture(texturesBody[tha_playa->counterMoving]);
      tha_playa->txtr_feet = load_texture(texturesFeet[tha_playa->counterMoving]);
      
      tha_playa->counterMoving = tha_playa->counterMoving + 1;
      break;
   }
}

void update_player(player *tha_playa, mouse *tha_mouse) {
  if (tha_playa->up) {
    moveY = 1;
    
    tha_playa->speed_y = (float)PLAYER_MAX_SPEED;
    tha_playa->y -= (int)PLAYER_MAX_SPEED;
  } 
  if (tha_playa->down){		
    moveY = 2;
    
    tha_playa->speed_y = (float)PLAYER_MAX_SPEED;
    tha_playa->y += (int)PLAYER_MAX_SPEED;	
  }
  if (tha_playa->left) {
    moveX = 1;	
    
    tha_playa->speed_x = (float)PLAYER_MAX_SPEED;
    tha_playa->x -= (int)PLAYER_MAX_SPEED;
  } 
  if (tha_playa->right) {
    moveX = 2;
    
    tha_playa->speed_x = (float)PLAYER_MAX_SPEED;
    tha_playa->x += (int)PLAYER_MAX_SPEED;	
  }

  // Make Sure It Slowly Walks Off (Y version) //
  if (tha_playa->speed_y <= 0) {
    moveY = 0;
  } 
  if (moveY != 0) {
    // Step 1: Get The Current Speed Of Blorp 		//
    float currentSpeed = (float)tha_playa->speed_y;

    // Step 2: Remove A Slight Bit Off That Speed 	//
    currentSpeed = (float)currentSpeed - PLAYER_DECELERATION;
    tha_playa->speed_y = (float)currentSpeed - PLAYER_DECELERATION;

    if (moveY == 1) {
      // Step 3: Set It To y Of Blorp 			//
      tha_playa->y = tha_playa->y - (int)currentSpeed;
    } else if (moveY == 2) {
      tha_playa->y = tha_playa->y + (int)currentSpeed;
    }
  }

  // Make Sure It Slowly Walks Off (X version) //
  if (tha_playa->speed_x <= 0) {
    moveX = 0;
  } 
  if (moveX != 0) {
    // Step 1: Get The Current Speed Of Blorp 		//
    float currentSpeed = (float)tha_playa->speed_x;

    // Step 2: Remove A Slight Bit Off That Speed 	//
    currentSpeed = (float)currentSpeed - PLAYER_DECELERATION;
    tha_playa->speed_x = (float)currentSpeed - PLAYER_DECELERATION;

    if (moveX == 1) {
      // Step 3: Set It To y Of Blorp 			//
      tha_playa->x = tha_playa->x - (int)currentSpeed;
    } else if (moveX == 2) {
      tha_playa->x = tha_playa->x + (int)currentSpeed;
    }
  }

  if (tha_playa->speed_x <= 0 && tha_playa->speed_y == 0) tha_playa->state = 0; // state 0 is for IDLE //

  tha_playa->angle = get_angle(tha_playa->x, tha_playa->y, tha_mouse->x, tha_mouse->y, tha_playa->txtr_body);
}
