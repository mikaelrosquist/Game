#include <iostream>
#include "SDL/SDL.h"
#include "MedBug.h"
#include "MinBug.h"
#include "BigBug.h"
#include "Player.h"
#include "Ship.h"
#include "Globals.h"
#include "Frame.h"
#include "GameEngine.h"
#include "Test.h"
#define MINBUGVALUE 10 // poäng för varje bug.
#define MEDBUGVALUE 20
#define BIGBUGVALUE 30

using namespace std;
using namespace engine;

Frame* createLevel1(){
    Frame* frame = new Frame(); // Skapa spelnivå och tillsätt Sprites
    
    int xPos = 0;
    
    for(int i=0 ; i<10 ; i++) {
        xPos += 50;
        frame->addBugs(MinBug :: getInstance(xPos,90,10,MINBUGVALUE,false));
        frame->addBugs(MedBug :: getInstance(xPos,140,10,MEDBUGVALUE,false));
        frame->addBugs(BigBug :: getInstance(xPos,190,10,BIGBUGVALUE,true));
    }
    
    frame->addPlayer(Player :: getInstance(400,500,10,5));
    
    //Ship* bug4 = Ship :: getInstance(10,60,10,5,false);
    //frame->addBugs(bug4);
    
    return frame;
}

Frame* createLevel2(){
    Frame* frame = new Frame(); // Skapa spelnivå och tillsätt Sprites
    
    int xPos = 0;
    
    for(int i=0 ; i<10 ; i++) {
        xPos += 50;
        frame->addBugs(MinBug :: getInstance(xPos,90,10,MINBUGVALUE,false));
        frame->addBugs(MedBug :: getInstance(xPos,140,10,MEDBUGVALUE,false));
        frame->addBugs(BigBug :: getInstance(xPos,190,10,BIGBUGVALUE,true));
    }
    
    frame->addPlayer(Player :: getInstance(400,500,10,5));
    Ship* bug4 = Ship :: getInstance(10,60,10,5,false);
    frame->addBugs(bug4);
    
    return frame;
}

/*
 Fixa
 - kollision metod
 - poäng räkning
 - byta bild
 - sätta hastighet
 - städa bort Sprites
 
 */
int main(int argc, char ** argv) {
    
    GameEngine engine; // Skapa och initiera motorn/händelseloopen
    engine.init();
    bool continueGame = true;
    std::vector<Frame*>frames;
    frames.push_back(createLevel1());
    frames.push_back(createLevel2());
    
    vector<Frame*>::iterator iter = frames.begin();
    
    while(continueGame && iter != frames.end()) {
        engine.setFrame(*iter);
        continueGame = engine.run(); // Om spelet ska fortsätta eller inte.
        iter++;
    }
    engine.gameOver();
	
    return 0;
}
