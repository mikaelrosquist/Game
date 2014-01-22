#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SDL/SDL.h>
#include <iostream>

namespace engine{
    
	struct Rectangle : public SDL_Rect{ // Den hålle reda på Sprite position.
		
        Rectangle();
		Rectangle(int xx, int yy, int ww, int hh);
		bool contains(int xx, int yy) const;
		Rectangle centeredRect(int width, int height) const;
		bool overlaps(const Rectangle& other) const;
	};
	
    std::ostream& operator<< (std::ostream &out, Rectangle &cPoint);
	
}

#endif
