#include "SpriteManager.h"

SpriteManager::SpriteManager() {}

SpriteManager::load_media() {
    //Load images as surfaces
    SDL_Surface* surf_default = IMG_Load("imgs/default-tex.png");
    SDL_Surface* surf_background_menu = IMG_Load("imgs/backgrounds/background-menu.png");
    SDL_Surface* surf_knight_idle = IMG_Load("imgs/heroes/knight-idle-sheet.png");
    SDL_Surface* surf_wizard_idle = IMG_Load("imgs/heroes/wizard-idle-sheet.png");
    SDL_Surface* surf_assassin_idle = IMG_Load("imgs/heroes/assassin-idle-sheet.png");

    //Convert surfaces to textures
    default_tex = SDL_CreateTextureFromSurface(rend, surf_default);
    background_menu = SDL_CreateTextureFromSurface(rend, surf_background_menu);
    knight_idle = SDL_CreateTextureFromSurface(rend, surf_knight_idle);
    wizard_idle = SDL_CreateTextureFromSurface(rend, surf_wizard_idle);
    assassin_idle = SDL_CreateTextureFromSurface(rend, surf_assassin_idle);

    //Destroy surfaces
    SDL_FreeSurface(surf_default);
    SDL_FreeSurface(surf_background_menu);
    SDL_FreeSurface(surf_knight_idle);
    SDL_FreeSurface(surf_wizard_idle);
    SDL_FreeSurface(surf_assassin_idle);
}

SpriteManager::addSprite(Sprite sprite) {
    activeSprites
}