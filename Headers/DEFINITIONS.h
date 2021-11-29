//
// Created by Luca Maltempo on 23/11/21.
//

#pragma once

#define  SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define  SPLASH_STATE_SHOW_TIME 3.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "../Resources/res/sky.png"
#define GAME_BACKGROUND_FILEPATH "../Resources/res/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "../Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "../Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "../Resources/res/PlayButton.png"
#define PIPE_UP_FILEPATH "../Resources/res/PipeUP.png"
#define PIPE_DOWN_FILEPATH "../Resources/res/PipeDown.png"
#define  LAND_FILEPATH "../Resources/res/Land.png"
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 1.5f
#define BIRD_ANIMATION_DURATION 0.6f
#define BIRD_FRAME_1_FILEPATH "../Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "../Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "../Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "../Resources/res/bird-04.png"
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3
#define GRAVITY 250.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.35f
#define ROTATION_SPEED 130.0f
#define BIRD_COLLISION_SCALE 0.625f
#define FULL_COLLISION_SCALE 1.0f


enum GameStates
{
    eReady,
    ePlaying,
    eGameOver
};