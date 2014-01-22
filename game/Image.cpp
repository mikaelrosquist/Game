#include "Image.h"

namespace engine {
    
    Image::Image() : img(NULL), transparent(false){
    }
    
    Image::Image(char* filename, bool trans) : transparent(trans) {
        img = IMG_Load(filename);
        if(trans){
            Uint32 transp = *(Uint32*) img->pixels;
            SDL_SetColorKey(img, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
        }
    }
    
    Image::~Image() {
        SDL_FreeSurface(img);
    }
    
    SDL_Surface* Image::getSurface() const {
        img->refcount++;//räknar upp refcount när man gör getSurface.
        return img;
    }
    
    int Image:: getWidth() const {
        return getSurface()->w;
    }
    int Image:: getHight() const {
        return getSurface()->h;
    }
}