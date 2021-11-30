//
// Created by Luca Maltempo on 23/11/21.
//
#pragma once

#include<sstream>
#include "../Headers/SplashState.h"
#include "../Headers/DEFINITIONS.h"
#include "../Headers/MainMenuState.h"
#include <iostream>

namespace Maltempo {

    SplashState::SplashState(GameDataRef data) : data(data) {

    }

    void SplashState::init() {
        data->assetManager.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        background.setTexture(this->data->assetManager.getTexture("Splash State Background"));
    }

    void SplashState::handleInput() {
        sf::Event event;
        while (data->renderWindow.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                data->renderWindow.close();
            }
        }
    }

    void SplashState::update(float dt) {
        if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
            data->stateMachine.addState(StateRef(new MainMenuState(data)), true);
        }
    }

    void SplashState::draw(float dt) {
        data->renderWindow.clear();
        data->renderWindow.draw(background);
        data->renderWindow.display();
    }
}