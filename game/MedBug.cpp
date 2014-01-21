#include "MedBug.h"
#include "Globals.h"
#include <SDL/SDL.h>


namespace engine{
    
    MedBug::MedBug(int x, int y, int w, int h, int value) : Bug(x,y,w,h,value){
     addImage(new Image("/Users/mikaelrosquist/Documents/Mikael/Plugg/Year III/Prog3/Game/Image/MedBug2.png", true));
        
    }
    
    void  MedBug::draw() {
            SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL,sys.screen, &rect);
		
	}
    
     MedBug:: ~ MedBug() {
         Bug::~Bug();
    }
    
    void MedBug::tick() {
        Bug::tick();
        
    }
    
    MedBug*  MedBug :: getInstance(int x, int y, int w, int h, int value) {
        return new  MedBug(x,y,w,h,value);
    }
    
    int MedBug::getValue(){
        return value;
    }
    
}
