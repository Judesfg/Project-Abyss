#include <sprite.h>

Sprite::Sprite(int xIn, int yIn, int wIn, int hIn, SDL_Texture* texIn) {
    x = xIn;
    y = yIn;
    w = wIn;
    h = hIn;
    u = 0;
    v = 0;
    tex = texIn;
}

nextFrame() {
            u = (u + w) % (w * 4);
        }