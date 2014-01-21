#include "Player.h"
#include "Globals.h"
#include <SDL/SDL.h>
#include "Bullet.h"
//#include "Rectangel.h"

namespace engine{
    
    Player::Player(int x, int y, int w, int h,  int value) : Sprite(x,y,w,h,speed), value(value){
        addImage(new Image("/Users/mikaelrosquist/Documents/Mikael/Plugg/Year III/Prog3/Game/Image/Player0.png", true));
    }
    
    void Player::draw() {
		SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL,sys.screen, &rect);
	}
    
    Player:: ~Player() {
        
    }
    
    void Player::tick() {
        // Gör något
    }
    
    Rectangle Player::getRect() const{ //används inte...
        return rect;
    }
    
    void Player::mouseDown(int x, int y){
		if (rect.contains(x,y))
			x++;
	}
    void Player::keyDown(SDLKey key) {
        if(keystate [SDLK_RIGHT])
			rect.x += 15;
        if(keystate [SDLK_LEFT])
            rect.x -= 15;
        if(keystate [SDLK_UP]) {
            Rectangle rectangel = rect.centeredRect(10,10);
            Bullet* bull = Bullet::getInstance(rectangel.x, rectangel.y, rectangel.w, rectangel.h, 0);
            sys.level->addBullets(bull);// Lägger in den i vectorn.
            bull->tick();
        }
    }

    Player* Player::getInstance(int x, int y, int w, int h, int value) {
        return new Player(x,y,w,h,value);
    }
    
}
