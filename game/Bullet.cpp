#include "Bullet.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    Bullet::Bullet(int x, int y, int direction, int speed) : Sprite(x,y,speed){
        setDirection(direction);
        addImage(new Image("../../../../../../Image/bullet.png", true));
    }
    
    void Bullet::draw() {
		SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL,sys.screen, &rect);
	}
    
    Bullet:: ~Bullet() {
        
    }
    
    void Bullet::tick() {
        rect.y += getSpeed();
        
    }
    Bullet* Bullet :: getInstance(int x, int y, int direction, int speed) {
        return new Bullet(x,y,direction, speed);
    }
    
}
