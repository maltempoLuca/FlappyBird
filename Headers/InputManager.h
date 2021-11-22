//
// Created by Luca Maltempo on 22/11/21.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace Maltempo {
    class InputManager {
    public:
        InputManager() {};

        ~InputManager() {};

        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button, sf::RenderWindow &window);

        sf::Vector2i  getMpusePosition(sf::RenderWindow & window);

    };

}

