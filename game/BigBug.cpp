#include "BigBug.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    BigBug::BigBug(int x, int y, int speed, int value, bool shoot) : Bug(x,y,speed,value,shoot){
        addImage(new Image("../../../../../../Image/BigBug3.png", true));
        addImage(new Image("../../../../../../Image/Ship_red.png", true));
        // Lägg till ytterligare en bild, byt mellan dessa med något interval (tick).
    }
    
    /*void BigBug::draw() {
	 SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL,sys.screen, &rect);
	 }*/
    
    BigBug:: ~BigBug() {
        
    }
    
    /*void BigBug::tick() {
	 Bug::tick();
	 
	 // Lägg till BigBug specifikt beteende här, t.ex. skjut!?
	 }*/
    
    BigBug* BigBug :: getInstance(int x, int y, int speed, int value,bool shoot) {
        return new BigBug(x,y,speed,value,shoot);
    }
    
}
