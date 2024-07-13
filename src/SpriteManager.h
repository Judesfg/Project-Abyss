#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class SpriteManager {
    public:
        Sprite[] activeSprites;
        SDL_Texture[] textures;

        //Declare textures
        SDL_Texture* background_menu;
        SDL_Texture* knight_idle;
        SDL_Texture* wizard_idle;
        SDL_Texture* assassin_idle;
        SDL_Texture* default_tex;

        //Declare destination rectangles
        SDL_Rect background_dest;

        Sprite knight;
        Sprite wizard;
        Sprite assassin;

        void load_media();
        void addSprite(Sprite sprite);
}