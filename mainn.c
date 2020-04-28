

#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "dep.h"
int main(){
//initializing the screen
SDL_Surface *screen;
charac c;
characPos cp;
SDL_Event event;
int Dir;
char Direction;
SDL_Rect persoPos;
  SDL_Rect posobj;
       
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initializeSDL:%s \n",SDL_GetError());
return 1;
}

screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption( "game", NULL);
int done = 0;
c = initChar();
showChar(&cp, c , screen);
 SDL_Flip(screen);
//Game loop starts
while (done == 0){
while(SDL_PollEvent(&event) == 1){
     switch(event.type){
case SDL_QUIT:
done = 0;
break;
          case SDL_KEYDOWN:
  moveChar (event,&posobj,Dir);
           
          break;
         
          case SDL_MOUSEBUTTONDOWN:
 moveCharByMouse(screen,&persoPos,event,Direction);
             break;
}
}
}
//end game loop
SDL_FreeSurface(screen);
SDL_Quit();

return 0;

}

