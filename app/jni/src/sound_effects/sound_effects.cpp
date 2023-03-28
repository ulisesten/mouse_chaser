//
// Created by ulises on 22/12/22.
//

#include "sound_effects.h"
#include "SDL_log.h"

/*Music::Music(){

}*/

bool SoundEffects::loadMedia(){

    sound1 = Mix_LoadWAV( "sounds/sound1.wav" );

    if( sound1 == nullptr )
    {
        SDL_Log( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    return true;
}

SoundEffects::~SoundEffects(){
    Mix_FreeChunk(sound1);
}

void SoundEffects::play() {
    Mix_PlayChannel(-1, sound1, 0);
    //Mix_PlayMusic(music, -1);
    //Mix_PauseMusic();
}

