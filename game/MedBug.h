
#ifndef __Game__MedBug__
#define __Game__MedBug__

#include <iostream>
#include <SDL/SDL.h>
#include "Bug.h"

namespace engine {
    
    class  MedBug: public Bug {
    private:
        int value;
        MedBug (MedBug& other); //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        MedBug& operator= (Bug& other); //Tilldelning läggs privat för att förhindra värdesemantik
        
        int countStep = 0;
		
        
		
    protected:
		MedBug(int x, int y, int speed, int value,bool shoot);//Konstruktor protected, bara subklasser har tillgång till den.
        
		
    public:
        static  MedBug* getInstance (int x, int y, int speed, int value,bool shoot);// För att förberda för subklasser av Medbug.
        ~MedBug();
    };
}


#endif /* defined(__Game__MedBug__) */
