#include "Test.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    Test::Test() {
        addImage(new Image("../../../../../../Image/Ship.png", true));
        addImage(new Image("../../../../../../Image/Ship_green.png", true));
    }
    
    void Test::draw() {
        SDL_BlitSurface(Sprite::images[space]->getSurface(), NULL,sys.screen, &rect);
        if(space == 0) {
            space++;
        }else if(space < images.size()){
            space = 0;
        }
	}
    
    Test:: ~Test() {
        
    }
    
    Test* Test :: getInstance() {
        return new Test();
    }
    
}
