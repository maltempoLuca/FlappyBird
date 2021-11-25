//
// Created by Luca Maltempo on 25/11/21.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Headers/State.h"
#include "../Headers/Game.h"

namespace Maltempo {
    class GameOverState : public State {
    public:
        GameOverState(GameDataRef data);

        void init();

        void handleInput();

        void update(float dt);

        void draw(float dt);

    private:
        GameDataRef data;
        sf::Sprite background;
    };

}

