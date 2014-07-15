#ifndef __Game__Sprite__
#define __Game__Sprite__

#include <SDL/SDL.h>
#include <vector>
#include "Image.h"
#include "Rectangle.h"
#define WIDTH 10
#define HEIGHT 10
#define SPEED 1
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

namespace engine {
    
    class Sprite {
    
    public:
        Rectangle rect;
        void addImage(Image* ny);
        virtual void tick();
        virtual void draw() = 0;// Alla subklasser måste ha denna metod.
        virtual void mouseDown(int x, int y);
		virtual void mouseUp(int x, int y);
		virtual void keyDown(SDLKey key);
		virtual void keyUp(SDLKey key);
        Rectangle getPosition() const;
        int getSpeed() const;
        //void collisionDetector();
        void setSpeed(int sp);
        void setPosition(int x, int y);
		int getYPosition();
        void setDirection(int d);
        int getDirection();
        Rectangle* getRect();
        virtual~Sprite();//Destruktor
        std::vector<Image*> images;// har en vector med bilder
    
    protected:
        Sprite();
        Sprite(int x, int y, int speed); // Konstruktor private för att inte kunna skapa new.
        
    private:
        int speed;
        Sprite(Sprite& other); //Copy-konstruktorn
        Sprite& operator= (Sprite& other); //Tilldelning
        int direction;
    };
	
}//engine


#endif /* defined(__Game__Sprite__) */
