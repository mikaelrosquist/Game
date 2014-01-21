#include "Globals.h"
#include <SDL/SDL.h>
#include <SDL_ttf/SDL_ttf.h>

namespace engine{
	
    Globals::Globals() {
	
	}
    
	Globals::~Globals()
	{
		SDL_Quit();
		TTF_CloseFont(fonten);
		TTF_Quit();
	}
    
    void Globals::init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
            std::cerr << "Cannot init SDL!!!" << std::endl;
            EXIT_FAILURE;
        }
        screen = SDL_SetVideoMode(800,600,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
        TTF_Init();
        fonten = TTF_OpenFont("/Library/Fonts/Arial Bold.ttf",20);
        
        SDL_EnableKeyRepeat(1, 20);// Hålla ner tangenten så rör sig player objektet.
        
    }
    
	Globals sys;
}