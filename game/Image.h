#ifndef __Game__Image__
#define __Game__Image__

#include <SDL/SDL.h>
#include "SDL_image/SDL_image.h"
#include <string>

namespace engine {
    
    class Image {
    private:
        SDL_Surface* img;
        bool transparent;
        
    public:
        Image();
        Image(char *filname, bool trans);
        ~Image();
        SDL_Surface* getSurface() const;
        int getWidth();
        int getHeight();
        unsigned char buf[24];
        int w, h;
    };
}

#endif /* defined(__Game__Image__) */
