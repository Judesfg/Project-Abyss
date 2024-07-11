#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite {
    public:
        int x;
        int y;
        int w;
        int h;
        int u;
        int v;
        SDL_Texture* tex;

        sprite(int xIn, int yIn, int wIn, int hIn, SDL_Texture* texIn) {
            x = xIn;
            y = yIn;
            w = wIn;
            h = hIn;
            u = 0;
            v = 0;
            tex = texIn;
        }
        
        void nextFrame() {
            u = (u + w) % (w * 4);
        }

}
