//
// Created by Luca Maltempo on 25/11/21.
//

#pragma once

#include<sstream>
#include "../Headers/GameState.h"
#include "../Headers/GameOverState.h"
#include "../Headers/DEFINITIONS.h"
#include <iostream>

namespace Maltempo {

    GameState::GameState(GameDataRef data) : data(data) {

    }

    void GameState::init() {
        std::cout << "Game State" << std::endl;
        data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        data->assets.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
        data->assets.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        data->assets.loadTexture("Land", LAND_FILEPATH);
        data->assets.loadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);

        pipe = new Pipe(data);
        land = new Land(data);
        bird = new Bird(data);

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
        pipe->movePipes(dt);
        if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
            pipe->randomisePipeOffset();
            pipe->spawnBottomPipe();
            pipe->spawnTopPipe();
            clock.restart();
        }
        land->moveLand(dt);
    }

    void GameState::draw(float dt) {
        data->window.clear();
        data->window.draw(background);
        pipe->drawPipes();
        land->drawLand();
        bird->draw();
        data->window.display();
    }
}