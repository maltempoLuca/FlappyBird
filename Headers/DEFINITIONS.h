//
// Created by Luca Maltempo on 23/11/21.
//

#pragma once

#define  SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define  SPLASH_STATE_SHOW_TIME 3.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Resources/res/Luchino Productions.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "../Resources/res/sky.png"
#define GAME_BACKGROUND_FILEPATH "../Resources/res/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "../Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "../Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "../Resources/res/PlayButton.png"
#define PIPE_UP_FILEPATH "../Resources/res/PipeUP.png"
#define PIPE_DOWN_FILEPATH "../Resources/res/PipeDown.png"
#define SCORING_PIPE_FILEPATH "../Resources/res/InvisibleScoringPipe.png"
#define LAND_FILEPATH "../Resources/res/Land.png"
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 1.5f
#define BIRD_ANIMATION_DURATION 0.6f
#define BRONZE_MEDAL_FILEPATH "../Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "../Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "../Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "../Resources/res/Platinum-Medal.png"
#define BIRD_FRAME_1_FILEPATH "../Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "../Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "../Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "../Resources/res/bird-04.png"
#define FLAPPY_FONT_FILEPATH "../Resources/fonts/FlappyFont.ttf"
#define GAME_OVER_TITLE_FILEPATH  "../Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH  "../Resources/res/Game-Over-Body.png"
#define HIGHSCORE_FILE_PATH  "../Resources/HighScore.txt"
#define SCORE_FONT_SIZE 100
#define SCORE_FONT_SIZE_GAME_OVER 56
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3
#define GRAVITY 250.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.35f
#define ROTATION_SPEED 130.0f
#define BIRD_COLLISION_SCALE 0.625f
#define FULL_COLLISION_SCALE 1.0f
#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 15
#define GOLD_MEDAL_SCORE 30
#define PLATINUM_MEDAL_SCORE 100


enum GameStates {
    eReady,
    ePlaying,
    eGameOver
};