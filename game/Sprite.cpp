#include "Sprite.h"
#include "Globals.h"


namespace engine {
    
    Sprite::Sprite(): rect(0, 0, WIDTH, HEIGHT), speed(SPEED){
    }
    Sprite::Sprite(int x, int y, int speed): rect(x, y, WIDTH, HEIGHT), speed(speed){
    }
    
    Sprite::~Sprite() {
    }
    
    //kunna hämta ut vilket håll sprite går åt.
    int Sprite::getDirection() {
        return direction;
    }
    
    
    void Sprite::addImage(Image* ny) {
        images.push_back(ny);
    }
    
    void Sprite::setSpeed(int sp) {
        speed = sp;
    }
    
    void Sprite::setPosition(int x, int y) {
        rect.x = x;
        rect.y = y;
    }
	
	int Sprite::getYPosition(){
		return rect.y;
	}
	
    //vilket håll sprite går åt.
    void Sprite::setDirection(int d) {
        Sprite::direction = d;
        if (d == UP)
            speed = -speed;
    }
    
    Rectangle Sprite::getPosition() const {//returnerar en kopia för att skydda orginalet.
        return rect;
    }
    int Sprite::getSpeed() const {
        return speed;
        
    }
	
    void Sprite::tick() {
        rect.x +=speed;
        rect.y +=speed;
		
        if(rect.x > sys.screen->w || rect.y > sys.screen->h) {
            rect.y = 0;
            rect.x = 0;
        }
    }
    
    Rectangle* Sprite::getRect(){
        return &rect;
    }
    
    void Sprite::mouseDown(int x,int y){
	}
	void Sprite::mouseUp(int x, int y){
	}
	void Sprite::keyDown(SDLKey key){
	}
	void Sprite::keyUp(SDLKey key){
	}
    
}


