#include "Bug.h"
#include "Globals.h"

namespace engine {
    
    Bug::Bug(int x, int y, int w, int h, int value) : Sprite(x,y,w,h,speed), value(value){
    }
    
    void Bug::draw() {
        SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL,sys.screen, &rect);
    }
    
    Bug::~Bug() {
        Sprite::~Sprite();
    }
    
    void Bug :: tick() {
        countStep++;
        
        if(countStep == 70){ 
            rect.y = rect.y+10;
            
        } else if(countStep < 70) {
            rect.x = rect.x +3;//rör sig steg åt höger.
            
            
        }else if(countStep < 140) {
            rect.x = rect.x -3;//rör sig steg åt vänster.
            
        }else{
            rect.y = rect.y +10;
            countStep = 0;
        }
    }
    
    Bug* Bug :: getInstance(int x, int y, int w, int h, int value) {
        return new Bug(x,y,w,h,value);
    }
    
    int Bug::getValue(){
        return value;
    }
}