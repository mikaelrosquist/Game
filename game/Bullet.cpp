#include "Bullet.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    Bullet::Bullet(int x, int y, int direction, int speed) : Sprite(x,y,speed){
        setDirection(direction);
        addImage(new Image("Image/bullet.png", true));
		addImage(new Image("Image/bullet_enemy.png", true));
    }
    
    void Bullet::draw() {
		if(getDirection() == DOWN)
			SDL_BlitSurface(Sprite::images[1]->getSurface(), NULL, sys.screen, &rect);
		else
			SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL, sys.screen, &rect);
	}
    
    Bullet::~Bullet() {
        
	}
    
    void Bullet::tick() {
			rect.y += getSpeed();
    }
	
    Bullet* Bullet :: getInstance(int x, int y, int direction, int speed) {
        return new Bullet(x,y,direction, speed);
    }
    
}
