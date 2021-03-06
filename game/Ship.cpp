#include "Ship.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    Ship::Ship(int x, int y, int speed, int value, bool shoot) : Bug(x,y,speed,value,shoot){
        addImage(new Image("Image/Ship_red.png", true));
        addImage(new Image("Image/Ship_green.png", true));
    }
    
	int i=0; int shipDelay=0;
    void Ship::draw() {
		shipDelay++;
        if (shipDelay >= 200){
            i++;
            if (i < 10)
                space = 0;
            else if(i < 20)
                space = 1;
            else if (i == 20)
                i = 0;
            SDL_BlitSurface(Sprite::images[space]->getSurface(), NULL,sys.screen, &rect);
        }
	}
    
    Ship:: ~Ship() {
        
    }
    
    void Ship::tick() {
		if (shipDelay == 399){
            rect.x = 0;
            shipDelay = 0;
        }
        if (shipDelay >= 200)
            rect.x = rect.x +5;
    }

    Ship* Ship :: getInstance(int x, int y, int speed, int value, bool shoot) {
        return new Ship(x,y,speed,value,shoot);
    }
    
}