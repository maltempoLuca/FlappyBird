//
// Created by Luca Maltempo on 29/11/21.
//

#include "../Headers/Collision.h"

namespace Maltempo {

    Collision::Collision() {

    }

    bool Collision::checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2) {
        bool result = false;
        sf::Rect<float> rect1 = sprite1.getGlobalBounds();
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();
        if (rect1.intersects(rect2))
            result = true;
        return result;
    }

    bool Collision::checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2) {
        bool result = false;

        sprite1.setScale(scale1, scale1);
        sprite2.setScale(scale2, scale2);

        sf::Rect<float> rect1 = sprite1.getGlobalBounds();
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();
        if (rect1.intersects(rect2))
            result = true;
        return result;
    }
}
