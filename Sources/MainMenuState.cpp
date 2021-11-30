//
// Created by Luca Maltempo on 23/11/21.
//

#include "../Headers/MainMenuState.h"
#include "../Headers/GameState.h"
#include<sstream>
#include "../Headers/DEFINITIONS.h"
#include <iostream>

namespace Maltempo {

    MainMenuState::MainMenuState(GameDataRef data) : data(data) {

    }

    void MainMenuState::init() {
        data->assetManager.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        data->assetManager.loadTexture("Game Title", GAME_TITLE_FILEPATH);
        data->assetManager.loadTexture("PlayButton", PLAY_BUTTON_FILEPATH);
        background.setTexture(this->data->assetManager.getTexture("Main Menu Background"));
        title.setTexture(this->data->assetManager.getTexture("Game Title"));
        playButton.setTexture(this->data->assetManager.getTexture("PlayButton"));
        title.setPosition((SCREEN_WIDTH / 2) - (title.getGlobalBounds().width / 2), title.getGlobalBounds().height / 2);
        playButton.setPosition((SCREEN_WIDTH / 2) - (playButton.getGlobalBounds().width / 2),
                               (SCREEN_HEIGHT / 2) - (playButton.getGlobalBounds().height / 2));
        data->renderWindow.setFramerateLimit(60);
    }

    void MainMenuState::handleInput() {
        sf::Event event;
        while (data->renderWindow.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                data->renderWindow.close();
            }

            if(data->inputManager.isSpriteClicked(playButton, sf::Mouse::Left, data->renderWindow)){
                data->stateMachine.addState(StateRef(new GameState(data)), true);
            }
        }
    }

    void MainMenuState::update(float dt) {
    }

    void MainMenuState::draw(float dt) {
        data->renderWindow.clear();
        data->renderWindow.draw(background);
        data->renderWindow.draw(title);
        data->renderWindow.draw(playButton);
        data->renderWindow.display();
    }
}





