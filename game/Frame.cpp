#include "Frame.h"
#include "SDL/SDL.h"
#include "Globals.h"
#include "Sprite.h"
#include "Bug.h"

#define FPS 60
#define MINBUGVALUE 10 // poäng för varje bug.
#define MEDBUGVALUE 20
#define BIGBUGVALUE 30

namespace engine {
    
    Frame :: Frame(void) {
    }
    
    void Frame :: init() {
    }
    
    void Frame:: draw() {
        for (int i =0; i<bugs.size();i++) {
            bugs[i]->draw();
        }
        for (int i =0; i<player.size();i++) {
            player[i]->draw();
        }
        for (int i =0; i<bullets.size();i++) {
            bullets[i]->draw();
        }
    }
	
    
    void Frame:: keyDown(SDLKey key) {
        for(int i=0;i<player.size();i++)
            player[i]->keyDown(key);
    }
    
    
    void Frame:: tick() {
        score = 0;
        
        for (int i =0; i<bugs.size();i++) {
            bugs[i]->tick();
        }
        
        for(int i=0;i<player.size();i++){
            player[i]->tick();
        }
        for(int i=0;i<bullets.size();i++){
            bullets[i]->tick();
        }
        
        checkBugCollision();
        if (quit)
            return;
        //checkPlayerCollision();
		
    }
    
    //kollar kollisioner mellan bullets och bugs
    void Frame::checkBugCollision() {
		
        for(int i=0;i<bullets.size();i++) {
            if (bullets[i]->getDirection() != DOWN) {
                Rectangle* rect1 = (bullets[i]->Sprite::getRect());
                
                for(int j=0;j<bugs.size();j++){
                    if (!bugs[j]->getErased()) {
                        Rectangle* rect2 = (bugs[j]->Sprite::getRect());
                        if (rect1->Rectangle::overlaps(*rect2)){
                            bugs[j]->setErased(true); // Om bugg är träffad, spars det i variabel erased.
                            quit = checkPlayerWin();
                            if (j != 0 && j != 3 && j != 6 && j != 9 && j && 12 && j != 15 && j != 18 && j != 21 && j != 24 && j != 27)
                                bugs[j-1]->setShoot(true);
                            score = bugs[j]->Bug::getValue();
                            bullets.erase(bullets.begin()+i);
                        }
                    }
                }
            }
        }
    }
    
    //kollar kollisioner mellan player och bullet
    void Frame::checkPlayerCollision() {
        for(int i=0;i<player.size();i++){
            Rectangle* rect1 = (player[i]->Sprite::getRect());
            
            for(int j=0;j<bullets.size();j++){
                if (bullets[j]->getDirection() != UP) {
                    Rectangle* rect2 = (bullets[j]->Sprite::getRect());
                    
                    if (rect1->Rectangle::overlaps(*rect2)){
                        player.erase(player.begin()+i); //tar bort player, ska väl egentligen bli 'game over' eller nåt.
                        if(player.empty()) {
                            quit = true; //Spelet ska avslutas
                        }
                    }
                    
                }
            }
        }
    }
    
    // Går igenom bugs och tittar om alla är träffade av bullet.
    bool Frame::checkPlayerWin(){
        for(int i = 0; i<bugs.size(); i++) {
            if(!bugs[i]->getErased())
                return false;
        }
        return true;
    }
    
    bool Frame::checkPlayerLoss() {
        return quit;
    }
    
    bool Frame::getQuit(){
        return quit;
    }
    
    int Frame::getScore() {
        return score;
    }
    
    void Frame::addBugs(Bug* ny) {
        bugs.push_back(ny);
    }
    
    void Frame::addPlayer(Sprite* p){
        player.push_back(p);
    }
    
    void Frame::addBullets(Sprite *b){
        bullets.push_back(b);
    }
    
    void Frame::addText(Text t){
        texts.push_back(t);
    }
    
    void Frame :: run () {
    }
    
    Frame :: ~Frame(void) {
        
    }
	
}


