#ifndef __Game__Sprite__
#define __Game__Sprite__

#include <SDL/SDL.h>
#include <vector>
#include "Sprite.h"
#include "Image.h"
#include "Rectangle.h"

namespace engine {
    
    class Sprite {
    
    private:
        Sprite ( Sprite& other); //Copy-konstruktorn
        Sprite& operator= (Sprite& other); //Tilldelning

    protected:
        int speed;
        Sprite (int x, int y, int w, int h, int speed); // Konstruktor private för att inte kunna skapa new.
        std::vector<Image*> images;// har en vector med bilder, kan ha hur många bilder som helst
        
    public:
        //Image Sprite::*imgpek;
        Rectangle rect;
        Rectangle* getRect();
        virtual ~Sprite();//Destruktor
        void addImage(Image* ny);
        virtual void tick();
        virtual void draw() = 0;// Alla subklasser måste ha denna metod.
        virtual void mouseDown(int x, int y);
		virtual void mouseUp(int x, int y);
		virtual void keyDown(SDLKey key);
		virtual void keyUp(SDLKey key);
        void setSpeed(int sp);
        int getSpeed() const;
        void setPosition(int x, int y);
        Rectangle getPosition();
         /*void getPosition();
        void collisionDetector();*/
    };

}//engine


#endif /* defined(__Game__Sprite__) */
