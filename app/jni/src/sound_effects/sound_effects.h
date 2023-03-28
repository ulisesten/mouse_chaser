//
// Created by ulises on 22/12/22.
//

#ifndef ANDROID_PROJECT_SOUND_EFFECTS_H
#define ANDROID_PROJECT_SOUND_EFFECTS_H

#include "SDL_mixer.h"

class SoundEffects {
    struct Mix_Chunk* sound1 = nullptr;

public:
    //Music();
    bool loadMedia();
    void play();

    ~SoundEffects();
};
#endif //ANDROID_PROJECT_SOUND_EFFECTS_H
