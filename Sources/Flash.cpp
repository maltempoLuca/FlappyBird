//
// Created by Luca Maltempo on 30/11/21.
//

#include "../Headers/Flash.h"

namespace Maltempo {

    Flash::Flash(GameDataRef data) : data(data) {
        shape = sf::RectangleShape(sf::Vector2f(data->renderWindow.getSize()));
        shape.setFillColor(sf::Color(255, 255, 255, 0)); // alpha = 0 == not visible at the start
        flashOn = true;
    }

    void Flash::show(float dt) {
        int alpha;
        if (flashOn) {
            alpha = (int) shape.getFillColor().a + (FLASH_SPEED * dt);
            if (alpha >= 255.0f) {
                alpha = 255.0f;
                flashOn = false;
            }
        } else {
            alpha = (int) shape.getFillColor().a - (FLASH_SPEED * dt);
            if (alpha <= 0.0f) {
                alpha = 0.0f;
                flashOn = false;
            }
        }
        shape.setFillColor(sf::Color(255, 255, 255, alpha));
    }


    void Flash::draw() {
        data->renderWindow.draw(shape);
    }
}