LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2
SDL_IMAGE_PATH := ../SDL2_image
SDL_MIXER_PATH := ../SDL2_mixer

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/$(SDL_IMAGE_PATH) $(LOCAL_PATH)/$(SDL_MIXER_PATH) $(LOCAL_PATH)/objects/mouse $(LOCAL_PATH)/objects/base_object $(LOCAL_PATH)/scenario $(LOCAL_PATH)/objects/composite $(LOCAL_PATH)/sound_effects

# Add your application source files here...
LOCAL_SRC_FILES := project_main.cpp objects/base_object/base_object.cpp objects/mouse/mouse.cpp scenario/scenario.cpp objects/composite/game_element_set.cpp sound_effects/sound_effects.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -lOpenSLES -llog -landroid

include $(BUILD_SHARED_LIBRARY)