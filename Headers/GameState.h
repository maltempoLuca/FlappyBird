//
// Created by Luca Maltempo on 25/11/21.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Headers/State.h"
#include "../Headers/Game.h"
#include "../Headers/Pipe.h"
#include "../Headers/Land.h"
#include "../Headers/Bird.h"
#include "../Headers/Collision.h"
#include "../Headers/Flash.h"


namespace Maltempo {
    class GameState : public State {
    public:
        explicit GameState(GameDataRef data);

        void init() override;

        void handleInput() override;

        void update(float dt) override;

        void draw(float dt) override;


    private:
        void checkCollisionWithLand();

        void checkCollisionWithPipes();

        void checkCollisionWithScoringPipes();

        sf::Clock clock;
        GameDataRef data;
        sf::Sprite background;
        Pipe *pipe;
        Land *land;
        Bird *bird;
        Flash *flash;

        int gameState;

        int score;
    };

}

