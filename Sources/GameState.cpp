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
        data->assets.loadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        data->assets.loadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        data->assets.loadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

        pipe = new Pipe(data);
        land = new Land(data);
        bird = new Bird(data);

        background.setTexture(this->data->assets.getTexture("Game Background"));

        gameState = GameStates::eReady;
    }

    void GameState::handleInput() {
        sf::Event event;
        while (data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                data->window.close();
            }

            if (data->input.isSpriteClicked(background, sf::Mouse::Left, this->data->window)) {
                if (gameState != eGameOver) {
                    gameState = ePlaying;
                    bird->tap();
                }
            }
        }
    }

    void GameState::update(float dt) {
        if (gameState != eGameOver) {
            bird->animate(dt);
            land->moveLand(dt);
        }
        if (gameState == ePlaying) {
            pipe->movePipes(dt);
            if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
                pipe->randomisePipeOffset();
                pipe->spawnBottomPipe();
                pipe->spawnTopPipe();
                clock.restart();
            }
            bird->update(dt);
            std::vector<sf::Sprite> landSprites = land->getLandSprites();
            for (auto &landSprite: landSprites) {
                if (Collision::checkSpriteCollision(bird->getSprite(), BIRD_COLLISION_SCALE, landSprite,
                                                    FULL_COLLISION_SCALE)) {
                    gameState = eGameOver;
                }
            }

            std::vector<sf::Sprite> pipeSprites = pipe->getPipeSprites();
            for (auto &pipeSprite: pipeSprites) {
                if (Collision::checkSpriteCollision(bird->getSprite(), 1.0f, pipeSprite,
                                                    FULL_COLLISION_SCALE)) {
                    gameState = eGameOver;
                }
            }
        }
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