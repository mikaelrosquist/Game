#include "MinBug.h"
#include "Globals.h"
#include <SDL/SDL.h>

namespace engine{
    
    MinBug::MinBug(int x, int y, int w, int h, int value) : Bug(x,y,w,h,value){
        addImage(new Image("/Users/mikaelrosquist/Documents/Mikael/Plugg/Year III/Prog3/Game/Image/MinBug1.png", true));
    }
    
    void MinBug::draw() {
		SDL_BlitSurface(Sprite::images[0]->getSurface(),NULL ,sys.screen, &rect);
	}
    
    MinBug:: ~MinBug() {
        Bug::~Bug();
    }
    
    void MinBug::tick() {
        Bug::tick();
    }

    MinBug* MinBug :: getInstance(int x, int y, int w, int h, int value) {
        return new MinBug(x,y,w,h,value);
    }
    
    int MinBug::getValue(){
        return value;
    }
    
}
