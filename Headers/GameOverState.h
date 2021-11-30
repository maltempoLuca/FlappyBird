//
// Created by Luca Maltempo on 25/11/21.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Headers/State.h"
#include "../Headers/Game.h"
#include "../Headers/GameState.h"

namespace Maltempo {
    class GameOverState : public State {
    public:
        GameOverState(GameDataRef data, int score);


        void init() override;

        void handleInput() override;

        void update(float dt) override;

        void draw(float dt) override;

    private:
        GameDataRef data;
        sf::Sprite background;
        sf::Sprite gameOverTitle;
        sf::Sprite gameOverContainer;
        sf::Sprite retryButton;
        sf::Sprite medal;

        sf::Text scoreText;
        sf::Text highScoreText;

        int score;
        int highScore;
    };

}

