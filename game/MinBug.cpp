#include "MinBug.h"
#include "Globals.h"
#include <SDL/SDL.h>

namespace engine{
    
    MinBug::MinBug(int x, int y, int speed, int value, bool shoot) : Bug(x,y, speed,value,shoot){
        addImage(new Image("Image/MinBug1.png", true));
        addImage(new Image("Image/Ship.png", true));
    }

    MinBug::~MinBug() {
        
    }

    MinBug* MinBug :: getInstance(int x, int y, int speed, int value, bool shoot) {
        return new MinBug(x,y,speed,value,shoot);
    }
    
}
