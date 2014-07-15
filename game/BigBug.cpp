#include "BigBug.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    BigBug::BigBug(int x, int y, int speed, int value, bool shoot) : Bug(x,y,speed,value,shoot){
        addImage(new Image("Image/BigBug3.png", true));
        addImage(new Image("Image/Ship.png", true));
        // Lägg till ytterligare en bild, byt mellan dessa med något interval (tick).
    }
    
    BigBug::~BigBug() {
        
    }
    
    BigBug* BigBug :: getInstance(int x, int y, int speed, int value,bool shoot) {
        return new BigBug(x,y,speed,value,shoot);
    }
    
}
