//
// Created by Luca Maltempo on 23/11/21.
//
#pragma once

#include <SFML/Graphics.hpp>
#include "../Headers/State.h"
#include "../Headers/Game.h"

namespace Maltempo {
    class SplashState : public State {
    public:
        explicit SplashState(GameDataRef data);

        void init() override;

        void handleInput() override;

        void update(float dt) override;

        void draw(float dt) override;

    private:
        GameDataRef data;
        sf::Clock clock;
        sf::Sprite background;
    };

}

