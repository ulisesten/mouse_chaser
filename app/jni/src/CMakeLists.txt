cmake_minimum_required(VERSION 3.6)

project(MY_APP)

find_library(SDL2 SDL2)
find_library(SDL2_Image SDL2_image)

add_library(main SHARED)

set(SRC project_main.cpp
        objects/base_object/base_object.cpp
        objects/mouse/mouse.cpp
        scenario/scenario.cpp
        )

target_sources(main PRIVATE ${SRC})

include_directories(
                            objects/mouse
                            objects/base_object
                            scenario
                        )

target_link_libraries(main SDL2 SDL2_Image)


