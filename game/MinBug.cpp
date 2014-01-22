#include "MinBug.h"
#include "Globals.h"
#include <SDL/SDL.h>

namespace engine{
    
    MinBug::MinBug(int x, int y, int speed, int value, bool shoot) : Bug(x,y, speed,value,shoot){
        addImage(new Image("../../../../../../Image/MinBug1.png", true));
        addImage(new Image("../../../../../../Image/Ship.png", true));
    }
    
    /*void MinBug::draw() {
	 SDL_BlitSurface(Sprite::images[0]->getSurface(),NULL ,sys.screen, &rect);
	 }*/
    
    MinBug:: ~MinBug() {
        
    }
    
    /*void MinBug::tick() {
	 Bug::tick();
	 }*/
	
    MinBug* MinBug :: getInstance(int x, int y, int speed, int value, bool shoot) {
        return new MinBug(x,y,speed,value,shoot);
    }
    
}
