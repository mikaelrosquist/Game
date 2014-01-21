#ifndef __Game__Player__
#define __Game__Player__

#include <iostream>
#include <SDL/SDL.h>
#include "Sprite.h"


namespace engine {
    
    class Player: public Sprite {
    private:
        int value;
         //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        Player& operator= (Sprite& other); //Tilldelning läggs privat för att förhindra värdesemantik
        
    protected:
        Player(int x, int y, int w, int h, int value);//Konstruktor protected, bara subklasser har tillgång till den.
        
        
    public:
        Player ( Player& other);
        static Player* getInstance (int x, int y, int w, int h, int value);// För att förberda för subklasser av player.
        ~Player();
        Player();
        void tick();
        void draw();
        void mouseDown(int x,int y);
        void keyDown(SDLKey key);
        Rectangle getRect() const;
        Uint8 *keystate = SDL_GetKeyState(NULL);
        
    };
}

#endif /* defined(__Game__Player__) */
