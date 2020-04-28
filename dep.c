#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "dep.h"

charac initChar (){
 charac c;
 c.spriteleft = IMG_Load("perso_l.png");
c.spriteright = IMG_Load("perso_r.png");
if((c.spriteleft == NULL) && (c.spriteright == NULL)){
 printf("enable to load the image\n");
}
 return c;
}
void showChar(characPos *cp, charac c, SDL_Surface * screen){
 SDL_Rect camera;
 camera.x = 0;
 camera.y = 0;
 camera.h = 61;
 camera.w = 65;
cp->position.x = 200;
cp->position.y = 200;
cp->position.h = c.spriteleft->h;
cp->position.w = c.spriteleft->w;
SDL_BlitSurface(c.spriteleft, &camera, screen, &cp->position);
}


void moveChar (SDL_Event event, SDL_Rect *posobj, int Dir){
switch (event.key.keysym.sym){
  case SDLK_UP:
  if(Dir != 1){
    posobj->y +=20;
  }
  break;
  case SDLK_RIGHT:
    if(Dir != 2){
      posobj->x +=20;
    }
  break;
  case SDLK_LEFT:
    if(Dir != 3){
        posobj->x -= 20;
      }
   break;
   case SDLK_DOWN:
     if(Dir != 4){
         posobj->y -= 20;
       }
    break;
  }

}
void moveCharByMouse(SDL_Surface *screen,SDL_Rect * persoPos, SDL_Event event, char Direction){
  switch(event.type){
         case SDL_MOUSEBUTTONUP:
             if(event.button.button == SDL_BUTTON_LEFT){
              persoPos->x += 10;
           }
 if(event.button.button == SDL_BUTTON_RIGHT){
              persoPos->x -= 10;
           }
         break;
   }
}
