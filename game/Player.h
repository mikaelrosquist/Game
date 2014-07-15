#ifndef __Game__Player__
#define __Game__Player__

#include <iostream>
#include <SDL/SDL.h>
#include "Sprite.h"

namespace engine {
    
    class Player: public Sprite {
    private:
        int lives;
        Player ( Player& other); //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        Player& operator= (Sprite& other); //Tilldelning läggs privat för att förhindra värdesemantik
        Uint8 *keystate = SDL_GetKeyState(NULL);
        
        
    protected:
        Player(int x, int y, int speed, int value);//Konstruktor protected, bara subklasser har tillgång till den.
        
        
    public:
        static Player* getInstance (int x, int y, int speed, int lives);// För att förberda för subklasser av player.
        ~Player();
        void tick();
        void draw();
        void setLives(int l);
        int getLives() const;
        void mouseDown(int x,int y);
        void keyDown(SDLKey key);
        
        
    };
}

#endif /* defined(__Game__Player__) */
