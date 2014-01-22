#include "Bug.h"
#include "Globals.h"
#include "Bullet.h"

namespace engine {
    
	Bug::Bug(int x, int y, int speed, int value, bool shoot) : Sprite(x,y,speed),value(value),shoot(shoot){
	}
	
	void Bug::draw() {
		
		if(erased)// Om inte träffad, så ritar vi ut buggen.
			return;
		
		SDL_BlitSurface(Sprite::images[0]->getSurface(), NULL,sys.screen, &rect);
	}
	
	Bug:: ~Bug() {
		
	}
	
	void Bug :: tick() {
		/*if(erased)//Om träffad så gör vi inget( buggen rör sig inte)
		 return;*/
		
		countStep++;
		static int countShoot = 0;
		countShoot++;
		
		// Hanterar rörels för hur bugs rör sig.
		if(countStep == 50){
			rect.y = rect.y+10;
		} else if(countStep < 50) {
			rect.x = rect.x +3;//rör sig steg åt höger.
		}else if(countStep < 100) {
			rect.x = rect.x -3;//rör sig steg åt vänster.
		}else{
			rect.y = rect.y +10;
			countStep = 0;
		}
		
		// Hanterar om bugs ska skjuta.
		if(countShoot > 100 && shoot) {// om bug får skjuta.
			Rectangle rectangel = rect.centeredRect(10,10);
			Bullet* bull = Bullet::getInstance(rectangel.x, rectangel.y+20, DOWN, 10);//plusar på y led för att den inte ska kollidera med sig själv.
			sys.level->addBullets(bull);// Lägger in den i vectorn.
			countShoot = 0;
		}
		
	}
	
    bool Bug::getErased() {
        return erased;
    }
    
    void Bug::setErased(bool erased) {
        Bug::erased = erased;
        shoot = false;
    }
    
    void Bug::setShoot(bool shoot) {
        Bug::shoot = shoot;
    }
    
    int Bug::getValue() {
        return value;
    }
    
    Bug* Bug :: getInstance(int x, int y, int speed, int value, bool shoot) {
        return new Bug(x,y,speed,value,shoot);
    }
}