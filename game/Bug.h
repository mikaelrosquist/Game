#ifndef __Game__Bug__
#define __Game__Bug__
#include <iostream>
#include "Sprite.h"

namespace engine {
    class Bug : public Sprite{
		
    private:
        int value;
        int countStep = 0;
        bool shoot;
        bool erased = false;// om buggen är träffad eller ej.
        
        Bug (Bug& other); //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        Bug& operator= (Sprite& other); //Tilldelning läggs privat för att förhindra värdesemantik
        
    protected:
        Bug(int x, int y, int speed, int value, bool shoot);//Konstruktor protected, bara subklasser har tillgång till den.
    public:
        int getValue();
        virtual void tick();
        void draw();
        bool getErased();
        void setErased(bool erased);
        void setShoot(bool shoot);
        static Bug* getInstance (int x, int y, int speed, int value, bool shoot);// För att förbereda för subklasser.
        ~Bug();
    };
}

#endif /* defined(__Game__Bug__) */
