//
// Created by Luca Maltempo on 26/11/21.
//

#pragma  once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace Maltempo {

    class Land {
    public:
        explicit Land(const GameDataRef& data);

        void moveLand(float dt);

        void drawLand();

    private:
        GameDataRef data;
        std::vector<sf::Sprite> landSprites;
    };
}


