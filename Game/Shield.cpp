#include "Shield.h"
#include "Globals.h"
#include <SDL/SDL.h>
#include "Bullet.h"

namespace engine{
    
    Shield::Shield(int x, int y, int speed, int value) : Sprite(x,y,speed),value(value){
        addImage(new Image("Image/shield_hit_0.png", true));
		addImage(new Image("Image/shield_hit_1.png", true));
		addImage(new Image("Image/shield_hit_2.png", true));
		addImage(new Image("Image/shield_hit_3.png", true));
		addImage(new Image("Image/shield_hit_4.png", true));
    }
    
    void Shield::draw() {
		SDL_BlitSurface(Sprite::images[value]->getSurface(), NULL,sys.screen, &rect);
	}
    
    Shield:: Shield() {
        
    }
    
    void Shield::tick() {
        
        // Gör något
        
    }
    void Shield::mouseDown(int x, int y){
		if (rect.contains(x,y))
			x++;
	}
	
    void Shield::keyDown(SDLKey key) {
		
    }
	
	bool Shield::changeImage(){
		if(value == 4)
			return true;
		++value;
		return false;
	}
	
    Shield* Shield :: getInstance(int x, int y, int speed, int value) {
        return new Shield(x,y,speed,0);
    }
    
}