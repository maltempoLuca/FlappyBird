//
// Created by Luca Maltempo on 23/11/21.
//
#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Maltempo {
    class SplashState : public State {
    public:
        SplashState(GameDataRef data);

        void init();

        void handleInput();

        void update(float dt);

        void draw(float dt);

    private:
        GameDataRef data;
        sf::Clock clock;
        sf::Texture backgroundTexture;
        sf::Sprite background;
    };

}

