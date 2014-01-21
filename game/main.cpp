#include <iostream>
#include "SDL/SDL.h"
#include "MedBug.h"
#include "MinBug.h"
#include "BigBug.h"
#include "Player.h"
#include "Ship.h"
#include "Globals.h"
#include "Frame.h"


using namespace std;
using namespace engine;

/*
    Fixa
    - kollision metod
    - poäng räkning
    - byta bild
    - sätta hastighet
    - städa bort Sprites
    -
 */
int main(int argc, char ** argv) {
    
    sys.init();
    Frame fram;//Namnet Frame verkar kollidera med Windows bib
    sys.level = &fram;
    fram.init();
    fram.run();
    
    /*if(SDL_Init(SDL_INIT_EVERYTHING) ==1) {
        cerr << "Kan inte initiera SDL! \n";
        exit (-1);
    }
    SDL_Surface* screen = SDL_SetVideoMode( 800,600,32, SDL_SWSURFACE|SDL_DOUBLEBUF);
    if( screen == NULL) {
        cerr << "Kan inte skapa skärm! \n";
        exit(-1);
    }
    Uint32 bgColor = SDL_MapRGB(screen->format, 255, 200, 200);
    SDL_FillRect(screen, NULL, bgColor);
    SDL_Flip(screen);
    
    Bug* buggen = new Bug(10,50,300,100);
    buggen->tick();
    SDL_Rect rect= {100,100,0,0};
    //SDL_BlitSurface(buggen->getSurface() NULL, screen, &rect)
    
    SDL_Delay(5000); */
    
    
    
    return 0;
}