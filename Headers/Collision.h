//
// Created by Luca Maltempo on 29/11/21.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace Maltempo {

    class Collision {
    public:
        Collision();

        static bool checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2); // with pure rectangle
        static bool checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2); // BOX2D or CHEAPMONK
    };
}


