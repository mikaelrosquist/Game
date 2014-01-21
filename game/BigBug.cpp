#include "BigBug.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    BigBug::BigBug(int x, int y, int w, int h, int value) : Bug(x,y,w,h,value){
        addImage(new Image("/Users/mikaelrosquist/Documents/Mikael/Plugg/Year III/Prog3/Game/Image/BigBug3.png", true));
        // Lägg till ytterligare en bild, byt mellan dessa med något interval (tick).
    }
    
    void BigBug::draw() {
		SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL, sys.screen, &rect);
	}
    
    BigBug:: ~BigBug() {
        Bug::~Bug();
    }
    
    void BigBug::tick() {
        Bug::tick();
        
        // Lägg till BigBug specifikt beteende här, t.ex. skjut!?
    }
    
    BigBug* BigBug :: getInstance(int x, int y, int w, int h, int value) {
        return new BigBug(x,y,w,h,value);
    }
    
    int BigBug::getValue(){
        return value;
    }
}