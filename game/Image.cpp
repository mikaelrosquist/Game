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
    
    int Image::getWidth() {
        w = (buf[16]<<24) + (buf[17]<<16) + (buf[18]<<8) + (buf[19]<<0);
        return w;
    }
    
    int Image::getHeight() {
        h = (buf[20]<<24) + (buf[21]<<16) + (buf[22]<<8) + (buf[23]<<0);
        return h;
    }
    
    SDL_Surface* Image::getSurface() const {
        img->refcount++;//räknar upp refcount när man gör getSurface.
        return img;
    }
    

}