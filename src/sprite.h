#pragma once

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
        int scale;
        SDL_Texture* tex;
        SDL_Rect src_rect;
        SDL_Rect dest_rect;

        Sprite(int xIn = 0, int yIn = 0, int wIn = 32, int hIn = 32, int uIn = 0, int vIn = 0);

        void setTexture(SDL_Texture* texIn);
        void nextFrame();
        void setRects();
};
