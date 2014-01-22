#ifndef __Game__BigBug__
#define __Game__BigBug__


#include <iostream>
#include <SDL/SDL.h>
#include "Bug.h"

namespace engine {
    
    class BigBug: public Bug {
    private:
        int value;
        BigBug ( BigBug& other); //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        BigBug& operator= (Bug& other); //Tilldelning läggs privat för att förhindra värdesemantik
        int countStep = 0;
        
    protected:
        BigBug(int x, int y, int speed, int value, bool shoot);//Konstruktor protected, bara subklasser har tillgång till den.
    public:
        static BigBug* getInstance (int x, int y, int speed, int value, bool shoot);// För att förbereda för subklasser av bigbug.
        ~BigBug();
        //void tick();
        //void draw();
    };
}

#endif /* defined(__Game__BigBug__) */
