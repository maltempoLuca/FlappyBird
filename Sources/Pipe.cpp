//
// Created by Luca Maltempo on 26/11/21.
//

#include "../Headers/Pipe.h"
#include "../Headers/DEFINITIONS.h"

namespace Maltempo {
    //TODO:: elimina le pipe che escono dallo schermo.

    Pipe::Pipe(GameDataRef data) : data(data) {

    }

    void Pipe::drawPipes() {
        for (const auto &pipeSprite: pipeSprites) {
            data->window.draw(pipeSprite);
        }
    }

    void Pipe::spawnBottomPipe() {
        sf::Sprite sprite(data->assets.getTexture("Pipe Up"));
        sprite.setPosition(data->window.getSize().x, data->window.getSize().y - sprite.getGlobalBounds().height);
        pipeSprites.push_back(sprite);
    }

    void Pipe::spawnTopPipe() {

        sf::Sprite sprite(data->assets.getTexture("Pipe Down"));
        sprite.setPosition(data->window.getSize().x, 0);
        pipeSprites.push_back(sprite);
    }

    void Pipe::movePipes(float dt) {
        for (int i = 0; i<pipeSprites.size(); i++) {
            sf::Vector2f position = pipeSprites.at(i).getPosition();
            float movement = PIPE_MOVEMENT_SPEED * dt;
            pipeSprites.at(i).move(-movement, 0);
            data->window.draw(pipeSprites.at(i));
        }
    }
}