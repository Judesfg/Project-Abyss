#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite::Sprite(int xIn, int yIn, int wIn, int hIn, int uIn, int vIn) {
    x = xIn; //x pos
    y = yIn; //y pos
    w = wIn; //width
    h = hIn; //height
    u = uIn; //tex x pos
    v = vIn; //tex y pos
    scale = 6;
    setRects();
    
}

void Sprite::setTexture(SDL_Texture* texIn) {
    tex = texIn;
}

void Sprite::nextFrame() {
    u = (u + w) % (w * 4);
    src_rect.x = u;
    setRects();
}

void Sprite::setRects() {
    src_rect = {u, v, h, w};
    dest_rect = {x, y, h*scale, w*scale};
}