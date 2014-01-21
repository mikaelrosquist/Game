#include "Bullet.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    Bullet::Bullet(int x, int y, int w, int h, int value) : Sprite(x,y,w,h,speed), value(value){
        addImage(new Image("/Users/mikaelrosquist/Documents/Mikael/Plugg/Year III/Prog3/Game/Image/bullet.png", true));
    }
    
    void Bullet::draw() {
		SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL,sys.screen, &rect);
	}
    
    Bullet:: ~Bullet() {
        
    }
    
    void Bullet::tick() {
        rect.y = rect.y -30;
    }
    
    Bullet* Bullet :: getInstance(int x, int y, int w, int h, int value) {
        return new Bullet(x,y,w,h,value);
    }
    
}
