//
// Created by Luca Maltempo on 30/11/21.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

namespace Maltempo {

    class HUD {
    public:
        HUD(const GameDataRef& data);

        void draw();

        void updateScore(int score);

    private:
        GameDataRef data;
        sf::Text scoreText;
    };


}

