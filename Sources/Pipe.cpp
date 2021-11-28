//
// Created by Luca Maltempo on 26/11/21.
//

#include "../Headers/Pipe.h"
#include "../Headers/DEFINITIONS.h"
#include "iostream"


namespace Maltempo {
    //TODO:: elimina le pipe che escono dallo schermo.

    Pipe::Pipe(GameDataRef data) : data(data), landHeight(data->assets.getTexture("Land").getSize().y),
                                   pipeSpawnYOffset(0) {
    }

    void Pipe::drawPipes() {
        for (const auto &pipeSprite: pipeSprites) {
            data->window.draw(pipeSprite);
        }
    }

    void Pipe::spawnBottomPipe() {
        sf::Sprite sprite(data->assets.getTexture("Pipe Up"));
        sprite.setPosition(data->window.getSize().x, data->window.getSize().y - sprite.getGlobalBounds().height - pipeSpawnYOffset);
        pipeSprites.push_back(sprite);
    }

    void Pipe::spawnTopPipe() {
        sf::Sprite sprite(data->assets.getTexture("Pipe Down"));
        sprite.setPosition(data->window.getSize().x, -pipeSpawnYOffset);
        pipeSprites.push_back(sprite);
    }

    void Pipe::movePipes(float dt) {
        for (int i = 0; i < pipeSprites.size(); i++) {
            float movement = PIPE_MOVEMENT_SPEED * dt;
            pipeSprites.at(i).move(-movement, 0);
            data->window.draw(pipeSprites.at(i));
            if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) {
                pipeSprites.erase(pipeSprites.begin() + i);
            }
        }
    }

    void Pipe::randomisePipeOffset() {
        pipeSpawnYOffset = (floatDistro(defEngine) * (float)(landHeight + 1.0));
    }
}