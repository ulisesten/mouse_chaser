//
// Created by ulises on 21/12/22.
//

#ifndef __I_GAME_ELEMENT_H__
#define __I_GAME_ELEMENT_H__

#include "SDL.h"

class IGameElement {
public:
    virtual void move() = 0;
    virtual void paint() = 0;
    virtual void update() = 0;
    virtual void setDirection() = 0;
    virtual void keyPressed(SDL_Event event) = 0;
};

#endif //__I_GAME_ELEMENT_H__
