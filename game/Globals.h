#ifndef __Game__Globals__
#define __Game__Globals__

#include <iostream>
#include <SDL/SDL.h>
#include <SDL_ttf/SDL_ttf.h>
#include "Frame.h"

namespace engine{
	
    struct Globals // Global, alla andra kommer åt
	{
		Globals();
		~Globals();
		SDL_Surface* screen;
        Frame* level;// Läger in en frame här för att få åtkomst genom sys.
		TTF_Font* fonten;
        void init();
        
	};
    
	extern Globals sys;//En globalt objekt som alla klasser kan komma åt. Den sätter själva gameskärmen.
    
} // namespace enging


#endif /* defined(__Game__Globals__) */
