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
#include "Shield.h"
#include "Text.h"


namespace engine{
    
    class Frame { // Är den klass som representerar en level i spelet.
    public:
        Frame();
        void addBugs(Bug* ny);//Lägger till en sprite i sin vector.
        void addPlayer(Sprite* p);
        void addBullets(Sprite* b);
        void addText(Text t);
		void addShield(Sprite* s);
		
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
        void checkShieldCollision();
		void checkBulletOutside();
        bool checkPlayerWin();//kontrollerar om player vunnit
        bool checkPlayerLoss();//kontrollerar om player har förlorat
        Sprite* getPlayer(int p) const;
        
    private:
        int score = 0;
        int lives = 3; //fick inte till det på nåt snyggt sätt, löser det såhär sålänge.
        bool quit = false; // Variabel som används för att avgöra om spel ska avslutas.
        bool playerWin = false; // Variabel som används för att avgöra om spelaren vunnit.
        std::vector<Bug*> bugs; // Håller en vector med Sprite objekt.
        std::vector<Sprite*> players;
        std::vector<Sprite*> bullets;
        std::vector<Text> texts;
		std::vector<Sprite*> shields;
        
        Text* livesField;
    };
}
#endif /* defined(__Game__Frame__) */

