//
// Created by Luca Maltempo on 23/11/21.
//

#include "../Headers/MainMenuState.h"
#include<sstream>
#include "../Headers/DEFINITIONS.h"
#include <iostream>

namespace Maltempo {

    MainMenuState::MainMenuState(GameDataRef data) : data(data) {

    }

    void MainMenuState::init() {
        data->assets.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        data->assets.loadTexture("Game Title", GAME_TITLE_FILEPATH);
        data->assets.loadTexture("PlayButton", PLAY_BUTTON_FILEPATH);
        background.setTexture(this->data->assets.getTexture("Main Menu Background"));
        title.setTexture(this->data->assets.getTexture("Game Title"));
        playButton.setTexture(this->data->assets.getTexture("PlayButton"));
        title.setPosition((SCREEN_WIDTH / 2) - (title.getGlobalBounds().width / 2), title.getGlobalBounds().height / 2);
        playButton.setPosition((SCREEN_WIDTH / 2) - (playButton.getGlobalBounds().width / 2),
                               (SCREEN_HEIGHT / 2) - (playButton.getGlobalBounds().height / 2));
    }

    void MainMenuState::handleInput() {
        sf::Event event;
        while (data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                data->window.close();
            }

            if(data->input.isSpriteClicked(playButton,sf::Mouse::Left, data->window)){
                std::cout<<"Go to Screen"<<std::endl;
            }
        }
    }

    void MainMenuState::update(float dt) {
//        if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
//            std::cout << "GO TO MAIN MENU" << std::endl;
//        }
    }

    void MainMenuState::draw(float dt) {
        data->window.clear();
        data->window.draw(background);
        data->window.draw(title);
        data->window.draw(playButton);
        data->window.display();
    }
}





