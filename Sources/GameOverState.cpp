//
// Created by Luca Maltempo on 25/11/21.
//
#pragma once

#include<sstream>
#include "../Headers/GameOverState.h"
#include "../Headers/DEFINITIONS.h"
#include "../Headers/MainMenuState.h"
#include <iostream>

namespace Maltempo {

    GameOverState::GameOverState(GameDataRef data) : data(data) {

    }

    void GameOverState::init() {
        std::cout<<"Game Over State"<<std::endl;
        data->assets.loadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        background.setTexture(this->data->assets.getTexture("Game Over Background"));
    }

    void GameOverState::handleInput() {
        sf::Event event;
        while (data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                data->window.close();
            }
        }
    }

    void GameOverState::update(float dt) {
    }

    void GameOverState::draw(float dt) {
        data->window.clear();
        data->window.draw(background);
        data->window.display();
    }
}