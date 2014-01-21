#include "GameEngine.h"
#include "GameEngine.h"
#include "SDL/SDL.h"
#include "Globals.h"
#include "Text.h"

#define FPS 60
#define FPSLOW 10// kunna allternera farten.
#define FPSMEDIUM 20
#define FPSHIGH 30

namespace engine {
    
    GameEngine :: GameEngine() : score(0), speed(FPSMEDIUM) {
        
    }
    
    void GameEngine :: init() {
        sys.init();
        screen = sys.screen;
        scoreField = new Text(200,20,30,30, "Score");
        score = 0;
    }
    
    void GameEngine :: setFrame(Frame* ny) {
        frame = ny;
        sys.level = ny; // Spara frame globalt i sys för att kommas åt i hela systemet.
    }
    void GameEngine :: run() {
        const int tickInterval = 2000/speed; //Tidtagningsfunktion, vilken hastighet händelseloppen går i.
        Uint32 nextTick;
        int delay;
        
        frame->draw();
    
        SDL_Flip(sys.screen);
        bool quit =false;
        while(!quit) {
            nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event eve;
            while(SDL_PollEvent(&eve)){// Kontrollerar om något har hänt
                switch (eve.type){// vilken typ?
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        frame->keyDown(eve.key.keysym.sym);
                        break;
                }
            }
            delay =nextTick - SDL_GetTicks();
            if(delay > 0)
                SDL_Delay(delay);
            
            Uint32 svart = SDL_MapRGB(sys.screen->format, 0, 0, 0);
            SDL_FillRect(sys.screen,NULL, svart);
            frame->tick();
            frame->draw();
            scoreField->setText(score);
            scoreField->draw();
            score++;
            SDL_Flip(sys.screen);
            
        }
    }
    GameEngine :: ~GameEngine() {
        
    }
    
}
