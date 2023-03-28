//
// Created by ulises on 15/12/22.
//

#ifndef ANDROID_PROJECT_MOUSE_H
#define ANDROID_PROJECT_MOUSE_H

#include <ctime>
#include <cstring>
#include <random>
#include "../base_object/base_object.h"
#include "objects/composite/i_game_element.h"
#include "sound_effects.h"

class Mouse: public BaseObject, public IGameElement {
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* object_surface = nullptr;
    SDL_Texture* object_texture = nullptr;
    int movement_range = 4;
    int vertical_movement_range;
    int horizontal_movement_range;
    int frame_index = -1;

    //Provisional
    SDL_Event event;
    SDL_Rect touch_rect{};

    bool increment_sprite_index = true;

    SoundEffects* music = nullptr;


public:

    Mouse(SDL_Renderer *renderer, int maxWidth, int maxHeight, const char *image_uri);

    void update();

    void keyPressed(SDL_Event event);
    void move();

    void paint();

    void setMovementRange(int movement_range){
        this->horizontal_movement_range = movement_range;
        this->vertical_movement_range = movement_range;
    }

    void setBounds(int width, int height){
        maxWidth = width;
        maxHeight = height;
    }

    void setDirection(int direction);
    void setDirection();
    void setVerticalDirection();
    void setHorizontalDirection();
    int getDirection() const;

    //double getRandom(int begin, int limit);
};

#endif //ANDROID_PROJECT_MOUSE_H
