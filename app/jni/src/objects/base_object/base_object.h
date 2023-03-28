#ifndef __BASE_OBJECT_H__
#define __BASE_OBJECT_H__

#include "SDL.h"
#include <iostream>
#include <cstring>

class BaseObject {
protected:
    SDL_Rect rect{};
    SDL_Rect sprite_rect{};
    int minWidth, minHeight, maxWidth, maxHeight;
    int x,y;
    bool isVisible = true;
    int frame_width;
    int frame_height;
    SDL_Point frame_mid_point;
    const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;
    int direction;
    int currentDirectionTime = 100;
    int directionTimeCounter = 0;

public:
    BaseObject(int x, int y);

    void setVisible(bool isVisible);
    bool getVisible() const;

    void setX(int x);
    void setY(int y);

    int getX();
    int getY();

    void setImageSurface(SDL_Surface* image_surface);
    bool getDetection(SDL_Rect rect);
};

#endif
