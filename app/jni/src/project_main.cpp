/**
  * Created by ulisesten on 8/25/22.
  */

#include <ctime>
#include "SDL.h"
#include "SDL_image.h"
#include "objects/mouse/mouse.h"
#include "scenario.h"
#include "game_element_set.h"
#include "../SDL2_mixer/SDL_mixer.h"


int main(int argc, char *argv[]) {
    SDL_Window *window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int maxWidth, maxHeight;


    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0) {
        SDL_Log("Error SDL_Init %s", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow("Mouse Chaser", 0, 0, 1080, 1920,SDL_WINDOW_OPENGL);


    if(!window) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return -2;
    }


    SDL_GetWindowSize(window, &maxWidth, &maxHeight);

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);


    if(!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s",
                     SDL_GetError());
        return -3;
    }



    if(IMG_Init(IMG_INIT_PNG) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                         "Couldn't init SDL_image: %s", SDL_GetError());
        return -4;
    }


    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return -5;
    }



    /// Game ///
    auto mouse1 = new Mouse(renderer, maxWidth, maxHeight, "mouse_sprite.png");
    //mouse1->setVisible(true);
    mouse1->setMovementRange(15);

    auto mouse2 = new Mouse(renderer, maxWidth, maxHeight, "mouse_sprite.png");
    //mouse2->setVisible(true);
    mouse2->setMovementRange(18);

    auto mouseSet = new GameElementSet();
    mouseSet->add(mouse1);
    mouseSet->add(mouse2);

    //Set = conjunto
    Scenario scenario(renderer, maxWidth, maxHeight, (IGameElement*)mouseSet);
    scenario.actionPerformed();



    // Clean up
    Mix_Quit();
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}