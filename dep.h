#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
typedef struct {
 SDL_Surface *spriteleft;
 SDL_Surface *spriteright;
}charac;
typedef struct {
 SDL_Rect position;
}characPos;
charac initChar ();
void showChar(characPos *cp, charac c, SDL_Surface * screen);
void moveChar (SDL_Event event, SDL_Rect *posobj, int Dir);
void moveCharByMouse(SDL_Surface *screen,SDL_Rect * persoPos, SDL_Event event, char whichDirection);



#end
