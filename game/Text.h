#ifndef __Game__Text__
#define __Game__Text__

#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include "Rectangle.h"

namespace engine{
    
    class Text {
		
    public:
        void draw();
        std::string getText() const;
        void setText(std::string newText);
        ~Text();
        Text(int x, int y, int w, int h, std::string txt);
        void setText(int newText);
		
    private:
        Rectangle rect;
        std::string text;
        std::string value;
        SDL_Surface* resultatyta;
        SDL_Color color;
    };
}

#endif /* defined(__Game__Text__) */
