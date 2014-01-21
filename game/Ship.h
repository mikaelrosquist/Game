#ifndef __Game__Ship__
#define __Game__Ship__
#include <iostream>
#include <SDL/SDL.h>
#include "Bug.h"

namespace engine {
    
    class Ship: public Bug {
    private:
        int space = 0;
        int value;
        Ship ( Ship& other); //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        Ship& operator= (Bug& other); //Tilldelning läggs privat för att förhindra värdesemantik
        
        
    protected:
        Ship(int x, int y, int w, int h, int value);//Konstruktor protected, bara subklasser har tillgång till den.
        
        
    public:
        static Ship* getInstance (int x, int y, int w, int h, int value);// För att förberda för subklasser av ship.
        ~Ship();
        void tick();
        void draw();
        
        
    };
}


#endif /* defined(__Game__Ship__) */
