//
// Created by ulises on 15/12/22.
//

#ifndef __ISCENARIO_H__
#define __ISCENARIO_H__

//#include "../../SDL2/include/SDL_events.h"
#include "SDL.h"

class IScenario {
public:
    virtual void paint() = 0;
    virtual void actionPerformed() = 0;
    virtual void keyPressed(SDL_Event event) = 0;
    virtual void keyReleased(SDL_Event event) = 0;
};

#endif //__ISCENARIO_H__
