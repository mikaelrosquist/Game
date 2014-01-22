#ifndef __Game__GameEngine__
#define __Game__GameEngine__
#include <iostream>
#include <vector>
#include "Frame.h"
#include "Text.h"

namespace engine{
    
    class GameEngine { // Är den klass som representerar en level i spelet.
    public:
        GameEngine();
        ~GameEngine();
        bool run();//Själva händelsloopen.
        void init(); //Fyller comps med Sprite
        void setFrame(Frame* ny);
        void gameOver();
        
    private:
        
        SDL_Surface* screen;
        Frame* frame;//spelplan
        Text* scoreField;
        int speed;
        int score;
        std::vector<int> highscores;
    };
}

#endif /* defined(__Game__GameEngine__) */
