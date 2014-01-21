
#ifndef __Game__Bug__
#define __Game__Bug__

#include <iostream>
#include "Sprite.h"

namespace engine {
    class Bug : public Sprite{
    
    private:
        int value;
        int countStep = 0;
        
        Bug (Bug& other); //Copy-konstruktorn läggs privat för att förhindra värdesemantik
        Bug& operator= (Sprite& other); //Tilldelning läggs privat för att förhindra värdesemantik
        
    protected:
        Bug(int x, int y, int w, int h, int value);//Konstruktor protected, bara subklasser har tillgång till den.
        
    
    public:
        virtual void tick();
        void draw();
        static Bug* getInstance (int x, int y, int w, int h, int value);// För att förbereda för subklasser av bigbug.
        virtual ~Bug();
        int getValue();
    };
}

#endif /* defined(__Game__Bug__) */
