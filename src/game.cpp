#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


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

        //Declare textures
        SDL_Texture* background_menu;

        //Declare destination rectangles
        SDL_Rect background_dest;


        Game(int width, int height) {
            quit = false;
            SCREEN_WIDTH = width;
            SCREEN_HEIGHT = height;
            background_dest.w = width;
            background_dest.h = height;
            background_dest.x = 0;
            background_dest.y = 0;
            create_window();
            load_media();
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
            SDL_Surface* surf_background_menu = IMG_Load("imgs/background-menu.png");

            //Convert surfaces to textures
            background_menu = SDL_CreateTextureFromSurface(rend, surf_background_menu);

            //Destroy surfaces
            SDL_FreeSurface(surf_background_menu);
        }

        void render() {
            //Clear the window
            SDL_RenderClear(rend);

            //Draw images
            SDL_RenderCopy(rend, background_menu, NULL, NULL);
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
            while (quit == false) {
                while(SDL_PollEvent(&e)) {
                    render();
                    SDL_Delay(1000/60); 
                    if(e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
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