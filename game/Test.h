#ifndef __Game__Test__
#define __Game__Test__
#include <iostream>
#include <SDL/SDL.h>
#include "Sprite.h"

namespace engine {
    
    class Test: public Sprite {
    private:
        int space = 0;
        int value;
        Test (Test& other); //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        Test& operator= (Sprite& other); //Tilldelning läggs privat för att förhindra värdesemantik
        
        
    protected:
        Test(); //Konstruktor protected, bara subklasser har tillgång till den.
        
        
    public:
        static Test* getInstance ();// För att förberda för subklasser av Test.
        ~Test();
        void draw();
        
        
    };
}


#endif /* defined(__Game__Test__) */
