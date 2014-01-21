#ifndef __F11__Frame__
#define __F11__Frame__

#include <iostream>
#include <vector>
#include "Sprite.h"
#include "MinBug.h"
#include "MedBug.h"
#include "BigBug.h"
#include "Ship.h"
#include "Player.h"
#include "Text.h"



namespace engine{
    
    class Frame { // Är den klass som representerar en level i spelet.
    public:
        Frame();
        void addBugs(Bug* ny);//Lägger till en sprite i sin vector.
        void addPlayer(Sprite* p);
        void addBullets(Sprite* b);
        void addText(Text* t);
        ~Frame();
        void run();//Själva händelsloopen.
        void init(); //Fyller comps med Sprite
        void draw();
        void keyDown(SDLKey key);
        void tick();
        
    private:
        int score;
        std::vector<Bug*> bugs; // Håller en vector med Sprite objekt.
        std::vector<Sprite*> player;
        std::vector<Sprite*> bullets;
        std::vector<Text*> texts;
    };
}
#endif /* defined(__Game__Frame__) */

