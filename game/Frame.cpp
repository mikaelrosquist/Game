#include "Frame.h"
#include "SDL/SDL.h"
#include "Globals.h"
#include "Sprite.h"
#include "Bug.h"

#define FPS 60
#define MINBUGVALUE 10 //poäng för varje bug.
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
        for (int i =0; i<players.size();i++) {
            players[i]->draw();
        }
        for (int i =0; i<bullets.size();i++) {
            bullets[i]->draw();
        }
		for (int i =0; i<shields.size();i++) {
            shields[i]->draw();
        }
    }
	
    
    void Frame:: keyDown(SDLKey key) {
        for(int i=0;i<players.size();i++)
            players[i]->keyDown(key);
    }
    
    
    void Frame:: tick() {
        score = 0;
        
        for (int i =0; i<bugs.size();i++) {
            bugs[i]->tick();
        }
        
        for(int i=0;i<players.size();i++){
            players[i]->tick();
        }
		
        for(int i=0;i<bullets.size();i++){
            bullets[i]->tick();
        }
		
		for (int i =0; i<shields.size();i++) {
            shields[i]->tick();
        }
        
        checkBugCollision();
		checkPlayerCollision();
		checkShieldCollision();

		checkBulletOutside();

        if (quit)
            return;
    }
    
    //kollar kollisioner mellan bullets och bugs
    void Frame::checkBugCollision() {
		
        for(int i=0;i<bullets.size();i++) {
            if (bullets[i]->getDirection() == UP) {
                Rectangle* rect1 = (bullets[i]->Sprite::getRect());
                
                for(int j=0;j<bugs.size();j++){
					Rectangle* rect2 = (bugs[j]->Sprite::getRect());
					if (rect1->Rectangle::overlaps(*rect2)){
						score += bugs[j]->Bug::getValue();
						bugs.erase(bugs.begin()+j);
						bullets.erase(bullets.begin()+i);
						quit = checkPlayerWin();
					}
				}
			}
		}
	}
    
    //kollar kollisioner mellan player och bullet
    void Frame::checkPlayerCollision() {
        for(int i=0;i<players.size();i++){
            Rectangle* rect1 = players[i]->Sprite::getRect();
            
            for(int j=0;j<bullets.size();j++){
                if (bullets[j]->getDirection() == DOWN) {
                    Rectangle* rect2 = bullets[j]->Sprite::getRect();
                    
                    if (rect1->Rectangle::overlaps(*rect2)){
						players.erase(players.begin()+i);
						bullets.erase(bullets.begin()+j);
						quit = true; //Spelet ska avslutas
					}
				}
			}
		}
	}
	
	//kollar kollisioner mellan bullet och shield
	void Frame::checkShieldCollision(){
		for(int i=0; i<bullets.size(); i++){
			Rectangle* rect1 = bullets[i]->Sprite::getRect();
			
			for(int j=0; j <shields.size(); j++){
				Rectangle* rect2 = shields[j]->Sprite::getRect();
				
				if (rect1->Rectangle::overlaps(*rect2)){
					Shield* tmp = dynamic_cast<Shield*>(shields[j]);
					bullets.erase(bullets.begin()+i);
					
					if(tmp->Shield::changeImage()) //byter bild och kollar om shield ska tas bort
						shields.erase(shields.begin()+j);
				}
			}
		}
	}
	
    // Går igenom bugs och tittar om alla är borta, undantag görs för Ship.
    bool Frame::checkPlayerWin(){
		if(bugs.empty())
			return true;
		else if(bugs.size() == 1)
			if(Ship* s = dynamic_cast<Ship*>(bugs[0])) //kanske finns snyggare lösning (onödigt att tilldela?)
				return true;
        return false;
    }
	
	// Tar bort bullets när de åker utanför skärmen
	void Frame::checkBulletOutside(){
        for(int i=0;i<bullets.size();i++) {
			if (bullets[i]->Sprite::getYPosition() < 0 || bullets[i]->Sprite::getYPosition() > 600){
				delete bullets[i];
				bullets.erase(bullets.begin()+i);
			}
        }
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
        players.push_back(p);
    }
	
	Sprite* Frame::getPlayer(int p) const{
		return players[p];
	}
	
	void Frame::addShield(Sprite* s){
        shields.push_back(s);
    }
    
    void Frame::addBullets(Sprite *b){
        bullets.push_back(b);
    }
    
    void Frame::addText(Text t){
        texts.push_back(t);
    }
    
    void Frame::run () {
    }
    
    Frame::~Frame() {
        
    }
	
}


