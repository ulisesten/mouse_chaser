#include "base_object.h"


BaseObject::BaseObject(int maxWidth, int maxHeight){
    this->x = 150;
    this->y = 150;
    this->minWidth = 0;
    this->minHeight = 0;
    this->maxWidth = maxWidth;
    this->maxHeight = maxHeight;

    //this->object_surface = IMG_Load(this->image_uri);
    //if(!object_surface) SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "Couldn't load surface: %s", IMG_GetError());


}


void BaseObject::setVisible(bool isVisible){
    this->isVisible = isVisible;
}

bool BaseObject::getVisible() const {
    return this->isVisible;
}

void BaseObject::setX(int x){
    this->x = x;
}

void BaseObject::setY(int y){
    this->y = y;
}

int BaseObject::getX(){
    return x;
}

int BaseObject::getY(){
    return y;
}

void BaseObject::setImageSurface(SDL_Surface* image_surface){
    //this->image_surface = image_surface;
}

bool BaseObject::getDetection(SDL_Rect _rect){
    return SDL_HasIntersection(&this->rect, &_rect);
}