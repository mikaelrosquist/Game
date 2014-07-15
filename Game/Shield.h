#ifndef __Game__Shield__
#define __Game__Shield__

#include <iostream>
#include <SDL/SDL.h>
#include "Sprite.h"

namespace engine {
    
    class Shield: public Sprite {
    private:
        int value;
        Shield ( Shield& other); //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        Shield& operator= (Sprite& other); //Tilldelning läggs privat för att förhindra värdesemantik
        Uint8 *keystate = SDL_GetKeyState(NULL);
        
        
    protected:
        Shield(int x, int y, int speed, int value);//Konstruktor protected, bara subklasser har tillgång till den.
        
        
    public:
        static Shield* getInstance (int x, int y, int speed, int value);// För att förberda för subklasser av player.
        Shield();
        void tick();
        void draw();
        void mouseDown(int x,int y);
        void keyDown(SDLKey key);
        bool changeImage();
    };
}

#endif /* defined(__Game__Shield__) */