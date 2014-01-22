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
        void addText(Text t);
		
        ~Frame();
        void run();//Själva händelsloopen.
        void init(); //Fyller comps med Sprite
        void draw();
        void keyDown(SDLKey key);
        void tick();
        bool getQuit();
        int getScore();
        void checkBugCollision();
        void checkPlayerCollision();
        bool checkPlayerWin();//kontrollerar om player vunnit
        bool checkPlayerLoss();//kontrollerar om player har förlorat
        
    private:
        int score = 0;
        bool quit = false; // Variabel som används för att avgöra om spel ska avslutas.
        bool playerWin = false; // Variabel som används för att avgöra om spelaren vunnit.
        std::vector<Bug*> bugs; // Håller en vector med Sprite objekt.
        std::vector<Sprite*> player;
        std::vector<Sprite*> bullets;
        std::vector<Text> texts;
    };
}
#endif /* defined(__Game__Frame__) */

