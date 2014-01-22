#include "Player.h"
#include "Globals.h"
#include <SDL/SDL.h>
#include "Bullet.h"
//#include "Rectangel.h"

namespace engine{
    
    Player::Player(int x, int y, int speed, int value) : Sprite(x,y,speed),value(value){
        addImage(new Image("../../../../../../Image/Player0.png", true));
    }
    
    void Player::draw() {
		SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL,sys.screen, &rect);
	}
    
    Player:: ~Player() {
        
    }
    
    void Player::tick() {
        
        // Gör något
        
    }
    void Player::mouseDown(int x, int y){
		if (rect.contains(x,y))
			x++;
	}
	
    void Player::keyDown(SDLKey key) {
        if(key == SDLK_RIGHT)
			rect.x += 10;
        if(key == SDLK_LEFT)
            rect.x -= 10;
        if(key == SDLK_UP) {
            Rectangle rectangel = rect.centeredRect(10,10);
            Bullet* bull = Bullet::getInstance(rectangel.x, rectangel.y, UP, 10);
            sys.level->addBullets(bull);// Lägger in den i vectorn.
        }
    }
	
    Player* Player :: getInstance(int x, int y, int speed, int value) {
        return new Player(x,y,speed,value);
    }
    
}
