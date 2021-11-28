//
// Created by Luca Maltempo on 28/11/21.
//

#include "../Headers/Bird.h"

namespace Maltempo {

    Bird::Bird(const GameDataRef& data) : data(data) {
        birdSprite.setTexture(data->assets.getTexture("Bird Frame 1"));
    }

    void Bird::draw() {
        data->window.draw(birdSprite);
    }
}
