#include "Frame.h"
#include "SDL/SDL.h"
#include "Globals.h"

#define FPS 60
#define MINBUGVALUE 30 // poäng för varje bug.
#define MEDBUGVALUE 20
#define BIGBUGVALUE 10
#define SHIPVALUE 100

namespace engine {
    
    Frame :: Frame(void) {
    }
    
    void Frame :: init() {
        int w = 0;
        int h = 0;
        int xPos = 0;
        for(int i=0 ; i<10 ; i++) {
            xPos += 50;
            addBugs(MinBug::getInstance(xPos,10,w,h,MINBUGVALUE));
            addBugs(MedBug::getInstance(xPos,60,w,h,MEDBUGVALUE));
            addBugs(BigBug::getInstance(xPos,110,w,h,BIGBUGVALUE));
        }
        
        addBugs(Ship::getInstance(10,10,w,h,SHIPVALUE));
        addPlayer(Player::getInstance(400,500,w,h,5));
    }
    
    void Frame:: draw() {
        for (int i =0; i<bugs.size();i++) {
            bugs[i]->draw();
        }
    }
    
    void Frame:: keyDown(SDLKey key) {
        for(int i=0;i<bugs.size();i++)
            bugs[i]->keyDown(key);
    }
    
    void Frame:: tick() {
        for (int i =0; i<bugs.size();i++) {
            bugs[i]->tick();
        }
    }
    
    void Frame::addBugs(Bug* ny) {
        bugs.push_back(ny);
    }
    
    void Frame::addPlayer(Sprite* p){
        player.push_back(p);
    }
    
    void Frame::addBullets(Sprite* b){
        bullets.push_back(b);
    }
    
    void Frame::addText(Text* t){
        texts.push_back(t);
    }
    
    //Skapar texten points
    Text points = Text::Text(650,550,50,30,"");
    Text scoreText = Text::Text(720,550,50,30,"");
    
    void Frame :: run () {
        const int tickInterval = 2000 /FPS;//Tidtagningsfunktion, vilken hastighet händelseloppen går i.
        Uint32 nextTick;
        int delay;
        
        SDL_Flip(sys.screen);//
        bool quit = false;
        bool freeze = false;
        while(!quit) {
            nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event eve;
            while(SDL_PollEvent(&eve)){// Kontrollerar om något har hänt
                switch (eve.type){// vilken typ?
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        for(int i=0;i<bugs.size();i++)
                            bugs[i]->keyDown(eve.key.keysym.sym);
                        for(int i=0;i<player.size();i++)
                            player[i]->keyDown(eve.key.keysym.sym);
                    default:
                        break;
                }
            }
            if(!freeze){
                delay = nextTick - SDL_GetTicks();
                if(delay > 0)
                    SDL_Delay(delay);
                
                Uint32 svart = SDL_MapRGB(sys.screen->format, 0, 0, 0);
                SDL_FillRect(sys.screen,NULL, svart);
                for (int i =0; i<bugs.size();i++) {
                    bugs[i]->tick();
                    bugs[i]->draw();
                }
                
                for(int i=0;i<player.size();i++){
                    player[i]->tick();
                    player[i]->draw();
                }
                
                for(int i=0;i<bullets.size();i++){
                    bullets[i]->tick();
                    bullets[i]->draw();
                }
                
                
                //kollar kollisioner mellan bullets och bugs
                for(int i=0;i<bullets.size();i++){
                    Rectangle* rect1 = (bullets[i]->Sprite::getRect());
                    
                    for(int j=0;j<bugs.size();j++){
                        Rectangle* rect2 = (bugs[j]->Sprite::getRect());
                        if (rect1->Rectangle::overlaps(*rect2)){
                            score += bugs[j]->Bug::getValue();
                            bugs.erase(bugs.begin()+j);
                            bullets.erase(bullets.begin()+i);
                        }
                    }
                }
                
                //kollar kollisioner mellan player och bugs
                for(int i=0;i<player.size();i++){
                    Rectangle* rect1 = (player[i]->Sprite::getRect());
                    
                    for(int j=0;j<bugs.size();j++){
                        Rectangle* rect2 = (bugs[j]->Sprite::getRect());
                        //Skriver ut Game over och stannar spelet om player kolliderar med en bug
                        if (rect1->Rectangle::overlaps(*rect2)){
                            Text gameOver = Text::Text(340,250,150,30,"Game Over");
                            gameOver.draw();
                            freeze = true;
                        }
                    }
                }
                
                //Uppdaterar och skriver ut score/points. Funkade inte att skriva points.draw() av någon anledning så därför sätts texten varje gång och draw() anropas från setText().
                points.setText("Score: ");
                scoreText.setText(score);
                
                SDL_Flip(sys.screen);
            }//if (!freeze)
        }
    }
    Frame :: ~Frame(void) {
        
    }
    
}


