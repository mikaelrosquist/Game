#include "Sprite.h"

using namespace engine;

Sprite::Sprite(int x, int y, int w, int h, int speed) : rect(x,y,w,h){ // Hårdkodar w och h till 10.
}

void Sprite :: addImage(Image* ny) {
    images.push_back(ny);
}

Sprite::~Sprite(){
    delete &rect;
}

void Sprite::tick() {
}
void Sprite::mouseDown(int x,int y){
}
void Sprite::mouseUp(int x, int y){
}
void Sprite::keyDown(SDLKey key){
}
void Sprite::keyUp(SDLKey key){
}
void getSize(int w, int h){
}
void Sprite::setSpeed(int sp) {
    speed = sp;
}
int Sprite::getSpeed() const {
    return speed;
}
void Sprite::setPosition(int x, int y) {
    rect.x = x;
    rect.y =y;
}
Rectangle Sprite::getPosition(){//returnerar en kopia för att skydda orginalet.
    return rect;
}
Rectangle* Sprite::getRect(){
    return &rect;
}



