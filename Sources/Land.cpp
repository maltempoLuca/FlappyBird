//
// Created by Luca Maltempo on 26/11/21.
//

#include "../Headers/Land.h"
#include "../Headers/DEFINITIONS.h"

namespace Maltempo {

    Land::Land(const GameDataRef& data) : data(data) {
        sf::Sprite sprite(data->assetManager.getTexture("Land"));
        sf::Sprite sprite2(data->assetManager.getTexture("Land"));
        sprite.setPosition(sprite.getGlobalBounds().width, data->renderWindow.getSize().y - sprite.getGlobalBounds().height);
        sprite2.setPosition(0, data->renderWindow.getSize().y - sprite.getGlobalBounds().height);
        landSprites.push_back(sprite);
        landSprites.push_back(sprite2);
    }

    void Land::moveLand(float dt) {
        for (auto & landSprite : landSprites) {
            float movement = PIPE_MOVEMENT_SPEED * dt;
            landSprite.move(-movement, 0.0f);

            if (landSprite.getPosition().x < 0 - landSprite.getGlobalBounds().width) {
                sf::Vector2f position(data->renderWindow.getSize().x, landSprite.getPosition().y);
                landSprite.setPosition(position);
            }
        }
    }

    void Land::drawLand() {
        for (const auto & landSprite : landSprites) {
            data->renderWindow.draw(landSprite);
        }
    }

    const std::vector<sf::Sprite> &Land::getLandSprites() const {
        return landSprites;
    }
}
