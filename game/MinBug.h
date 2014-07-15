#ifndef __Game__MinBug__
#define __Game__MinBug__

#include <iostream>
#include <SDL/SDL.h>
#include "Bug.h"
#include "Frame.h"

namespace engine {
    
    class MinBug: public Bug {
    private:
        int value;
        MinBug (MinBug& other); //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        MinBug& operator= (Bug& other); //Tilldelning läggs privat för att förhindra värdesemantik
        int countStep = 0;
        
    protected:
        MinBug(int x, int y, int speed, int value,bool shoot);//Konstruktor protected, bara subklasser har tillgång till den.
        
        
    public:
        static MinBug* getInstance (int x, int y, int speed, int value, bool shoot);// För att förberda för subklasser av Minbug.
        ~MinBug();
    };
}
#endif /* defined(__Game__MinBug__) */
