#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SDL/SDL.h>

namespace engine{
    
	struct Rectangle : public SDL_Rect{ // Den hålle reda på Sprite position.
		
        Rectangle();
       // ~Rectangle();
		Rectangle(int xx, int yy, int ww, int hh);
		bool contains(int xx, int yy) const;
		Rectangle centeredRect(int width, int height) const;
		bool overlaps(Rectangle other);
	};
    
} // cwing

#endif
