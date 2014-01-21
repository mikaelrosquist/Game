#include "Text.h"
#include "Globals.h"
#include <SDL/SDL.h>
#include <iostream>
using namespace std;

namespace engine{
    
    // Vilken font,texten och färgen till surfacen.
    Text::Text(int x, int y, int w, int h, string t): rect(x,y,w,h), text(t) {
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
      //  SDL_FreeSurface(resultatyta);
    }
    
  /*  const Text& Text::operator+=(std::string other){
        text += other;
        return *this;
    }
   */
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
        SDL_FreeSurface(resultatyta);
        resultatyta = TTF_RenderText_Solid(sys.fonten, value.c_str(), color);
        draw();
    }
    
    //liten ändring...
}