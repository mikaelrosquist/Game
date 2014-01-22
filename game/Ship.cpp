#include "Ship.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    Ship::Ship(int x, int y, int speed, int value, bool shoot) : Bug(x,y,speed,value,shoot){
        addImage(new Image("../../../../../../Image/Ship_red.png", true));
        addImage(new Image("../../../../../../Image/Ship_green.png", true));
    }
    
    void Ship::draw() {
        SDL_BlitSurface(Sprite::images[space]->getSurface(), NULL,sys.screen, &rect);
        if(space == 0) {
            space++;
        }else if(space < images.size()){
            space = 0;
        }
	}
    
    Ship:: ~Ship() {
        
    }
    
    void Ship::tick() {
        rect.x = rect.x +3;
		
    }
    
    Ship* Ship :: getInstance(int x, int y, int speed, int value, bool shoot) {
        return new Ship(x,y,speed,value,shoot);
    }
    
}
