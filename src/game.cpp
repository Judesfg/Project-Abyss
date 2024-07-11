#include <iostream>
#include <SDL2/SDL.h>

enum State {MENU, SETTINGS, GAME};

class Game {
    public:
        bool quit;
        State currentState = MENU;
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT;
        SDL_Window* window;
        SDL_Surface* screenSurface;
        SDL_Event e;


        Game(int width, int height) {
            quit = false;
            SCREEN_WIDTH = width;
            SCREEN_HEIGHT = height;
            create_window();
            gameLoop();
        }

        void create_window() {
            window = SDL_CreateWindow("Project Abyss", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
            
            if(window == NULL) {
                printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            }
            else {
                //Get window surface
                screenSurface = SDL_GetWindowSurface(window);

                //Fill the surface white
                SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

                //Update the surface
                SDL_UpdateWindowSurface(window);
            }
        }

        bool loadMedia() {
            bool success = true;
            return success;

            //background_menu = SDL_LoadJPG()
        }

        void gameLoop() {
            while (quit == false) {
                while(SDL_PollEvent(&e)) {
                    if(e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
            }
            //Destroy window
            SDL_DestroyWindow(window);

            //Quit SDL subsystems
            SDL_Quit();
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