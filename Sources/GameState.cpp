//
// Created by Luca Maltempo on 25/11/21.
//

#pragma once

#include<sstream>
#include "../Headers/GameState.h"
#include "../Headers/DEFINITIONS.h"
#include <iostream>

namespace Maltempo {

    GameState::GameState(GameDataRef data) : data(data) {

    }

    void GameState::init() {
        std::cout<<"Game State"<<std::endl;
        data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        background.setTexture(this->data->assets.getTexture("Game Background"));
    }

    void GameState::handleInput() {
        sf::Event event;
        while (data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                data->window.close();
            }
        }
    }

    void GameState::update(float dt) {
    }

    void GameState::draw(float dt) {
        data->window.clear();
        data->window.draw(background);
        data->window.display();
    }
}