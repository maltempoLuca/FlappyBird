//
// Created by Luca Maltempo on 22/11/21.
//

#include "../Headers/InputManager.h"

namespace Maltempo {

    bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
        if (sf::Mouse::isButtonPressed(button)) {
            sf::IntRect tmpRect(object.getPosition().x, object.getPosition().y, object.getLocalBounds().width,
                                object.getLocalBounds().height);
            if(tmpRect.contains(sf::Mouse::getPosition(window))){
                return true;
            }
        }
        return false;
    }

    sf::Vector2i InputManager::getMpusePosition(sf::RenderWindow &window) {
        return sf::Mouse::getPosition(window);
    }
}