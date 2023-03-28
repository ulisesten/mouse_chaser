//
// Created by ulises on 15/12/22.
//
#include <string>
#include "mouse.h"
#include "SDL_image.h"


Mouse::Mouse(SDL_Renderer *renderer, int maxWidth, int maxHeight, const char *image_uri)
        : BaseObject(maxWidth, maxHeight) {

    this->renderer = renderer;
    this->maxWidth = maxWidth;
    this->maxHeight = maxHeight;
    setHorizontalDirection();
    this->direction = getDirection();
    frame_width = 117;
    frame_height = 282;

    frame_mid_point = { frame_width / 2, (frame_height / 4) * 3};

    music = new SoundEffects();
    music->loadMedia();
    rect.x = 100;
    rect.y = 550;
    rect.w = frame_width;
    rect.h = frame_height;

    sprite_rect.x = 0;
    sprite_rect.y = 0;
    sprite_rect.w = frame_width;
    sprite_rect.h = frame_height;

    vertical_movement_range = movement_range;
    horizontal_movement_range = movement_range;

    this->object_surface = IMG_Load(image_uri);
    if(!object_surface) SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "Couldn't load surface: %s", IMG_GetError());

    this->object_texture = SDL_CreateTextureFromSurface(this->renderer, this->object_surface);
    if(!this->object_texture)
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Couldn't load texture: %s", SDL_GetError());


    SDL_FreeSurface(object_surface);

}


void Mouse::update() {
    if(frame_index == 2)
        increment_sprite_index = false;

    if(frame_index == -1)
        increment_sprite_index = true;


    if(increment_sprite_index) {
        ++frame_index;
        sprite_rect.x += frame_width;
    } else {
        --frame_index;
        sprite_rect.x -= frame_width;
    }
}


void Mouse::move(){

    ///Sobrepasa límite izquierdo
    if (rect.x <= minWidth) {
        setDirection(RIGHT);
    }

    ///Sobrepasa límite derecho
    else if((rect.x + rect.w) >= maxWidth){
        setDirection(LEFT);
    }

    ///Sobrepas límite superior
    else if (rect.y <= minHeight) {
        setDirection(DOWN);
    }

    ///Sobrepasa límite inferior
    else if((rect.y + rect.h) >= maxHeight){
        setDirection(UP);
    }

    if( direction == RIGHT ) {
        rect.x += horizontal_movement_range;
    }

    else if( direction == LEFT) {
        rect.x -= horizontal_movement_range;
    }

    else if( direction == UP ) {
        rect.y -= vertical_movement_range;
    }

    else if( direction == DOWN ) {
        rect.y += vertical_movement_range;
    }

}

void Mouse::paint(){
    if(BaseObject::isVisible) {

        if (direction == UP) {
            SDL_RenderCopy(
                    this->renderer,
                    object_texture, &sprite_rect, &rect
                    );
        } else if (direction == DOWN) {
            SDL_RenderCopyEx(this->renderer,
                             this->object_texture,
                             &sprite_rect,
                             &rect,
                             180,
                             &frame_mid_point, SDL_FLIP_HORIZONTAL);
        } else if (direction == RIGHT) {
            SDL_RenderCopyEx(this->renderer,
                             this->object_texture,
                             &sprite_rect,
                             &rect,
                             90,
                             &frame_mid_point, SDL_FLIP_HORIZONTAL);
        } else if (direction == LEFT) {
            SDL_RenderCopyEx(this->renderer,
                             this->object_texture,
                             &sprite_rect,
                             &rect,
                             -90,
                             &frame_mid_point, SDL_FLIP_HORIZONTAL);
        }

    }
}


void Mouse::setDirection(int direction) {
    this->direction = direction;
}

void Mouse::setDirection() {
    if(directionTimeCounter > currentDirectionTime) {
        direction = rand() % 4;
        directionTimeCounter = 0;
        currentDirectionTime = (rand() % 200) + 200;
        if(music)
            music->play();
    }

    directionTimeCounter++;
}


void Mouse::setVerticalDirection() {
    direction = (rand() % 2) + 2;
}

void Mouse::setHorizontalDirection() {
    direction = rand() % 2;
}


int Mouse::getDirection() const {
    return this->direction;
}

void Mouse::keyPressed(SDL_Event event) {
    /// 0 - 1
    ///This may be duplicating the events
    touch_rect = {(int)(event.tfinger.x * maxWidth),
                  (int)(event.tfinger.y * maxHeight),
                  frame_width,
                  frame_height };

    SDL_Log("%d", getDetection(touch_rect));

}


