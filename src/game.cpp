#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"

enum State {MENU, SETTINGS, GAME};

class Game {
    public:
        //Declare game variables
        bool quit;
        State currentState = MENU;
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT;
        SDL_Window* window;
        SDL_Renderer* rend;
        SDL_Surface* screenSurface;
        SDL_Event e;



        Game(int width, int height) {
            quit = false;
            SCREEN_WIDTH = width;
            SCREEN_HEIGHT = height;
            create_window();
            load_media();

            //REMOVE LATER
            knight = Sprite(SCREEN_WIDTH/2 - 32, SCREEN_HEIGHT/2 - 16, 32, 32, 0, 0);
            knight.setTexture(knight_idle);
            wizard = Sprite(SCREEN_WIDTH/4 - 32, SCREEN_HEIGHT/2 - 16, 32, 32, 0, 0);
            wizard.setTexture(wizard_idle);
            assassin = Sprite(3*SCREEN_WIDTH/4 - 32, SCREEN_HEIGHT/2 - 16, 32, 32, 0, 0);
            assassin.setTexture(assassin_idle);

            game_loop();
        }

        void create_window() {
            window = SDL_CreateWindow("Project Abyss", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
            
            if(window == NULL) {
                printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            }
            else {
                //Create renderer
                Uint32 renderFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
                rend = SDL_CreateRenderer(window, -1, renderFlags);
                if (!rend) {
                    std::cout << "Error creating renderer: " << SDL_GetError() << "/n";
                    //Destroy window
                    SDL_DestroyWindow(window);

                    //Quit SDL subsystems
                    SDL_Quit();
                }
                //Get window surface
                screenSurface = SDL_GetWindowSurface(window);

                //Update the surface
                SDL_UpdateWindowSurface(window);
            }
        }

        void load_media() {
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

        void render() {
            //Clear the window
            SDL_RenderClear(rend);

            //Draw images
            SDL_RenderCopy(rend, background_menu, NULL, NULL);
            SDL_RenderCopy(rend, knight.tex, &knight.src_rect, &knight.dest_rect);
            SDL_RenderCopy(rend, wizard.tex, &wizard.src_rect, &wizard.dest_rect);
            SDL_RenderCopy(rend, assassin.tex, &assassin.src_rect, &assassin.dest_rect);

            //Finalise
            SDL_RenderPresent(rend);
        }

        void game_exit() {
            //Clean up textures
            SDL_DestroyTexture(background_menu);

            //Clean up renderer
            SDL_DestroyRenderer(rend);

            //Destroy window
            SDL_DestroyWindow(window);

            //Quit SDL subsystems
            SDL_Quit();
        }

        void game_loop() {
            int tickCounter;
            while (quit == false) {
                tickCounter = (tickCounter + 1) % 60;
                if ((tickCounter % 15) == 0) {
                    //Update all sprites
                    knight.nextFrame();
                    wizard.nextFrame();
                    assassin.nextFrame();
                }
                while(SDL_PollEvent(&e)) {
                    
                    if(e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
                render();
                SDL_Delay(1000/60); 
            }
            game_exit();
        }
};

int main(int argc, char* args[]) {
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else {
        Game game(1280, 720);
    }
    return 0;
}