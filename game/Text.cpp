#include "Text.h"
#include "Globals.h"
#include <SDL/SDL.h>
#include <iostream>
using namespace std;

namespace engine{
    
    // Vilken font,texten och färgen till surfacen.
    Text::Text(int x, int y, int w, int h, string txt): rect(x,y,w,h), text(txt) {
        color = {255,255,255};
        resultatyta = TTF_RenderText_Solid(sys.fonten, text.c_str(), color);
    }
    
    // Tar fram en färg(col) och fyller rect och ritar ut.
    void Text::draw() {
        Uint32 col = SDL_MapRGB(sys.screen->format, 0,0,0);
        SDL_FillRect(sys.screen, &rect, col);
        SDL_BlitSurface(resultatyta,NULL,sys.screen, &rect);
    }
    
    Text::~Text(){
        SDL_FreeSurface(resultatyta);
    }
    
    string Text::getText() const {
        return text;
    }
    
    void Text::setText(std::string newText) {
        text = newText;
        SDL_FreeSurface(resultatyta);
        resultatyta = TTF_RenderText_Solid(sys.fonten, text.c_str(), color);
        draw();
    }
    
    void Text::setText(int newText) {
        value = to_string(newText);
        string txt = text + " " + value;
        SDL_FreeSurface(resultatyta);
        resultatyta = TTF_RenderText_Solid(sys.fonten, txt.c_str(), color);
        draw();
    }
	
	
    
}