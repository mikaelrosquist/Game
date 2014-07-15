#include "MedBug.h"
#include "Globals.h"
#include <SDL/SDL.h>



namespace engine{
    
    MedBug::MedBug(int x, int y, int speed, int value, bool shoot) : Bug(x,y,speed,value,shoot){
		addImage(new Image("Image/MedBug2.png", true));
		addImage(new Image("Image/Ship.png", true));
    }

	MedBug::~MedBug() {
        
    }
    
    MedBug* MedBug :: getInstance(int x, int y, int speed, int value, bool shoot) {
        return new  MedBug(x,y,speed,value,shoot);
    }
    
}
