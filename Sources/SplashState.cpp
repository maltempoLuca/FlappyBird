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
        data->assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        background.setTexture(this->data->assets.getTexture("Splash State Background"));
    }

    void SplashState::handleInput() {
        sf::Event event;
        while (data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                data->window.close();
            }
        }
    }

    void SplashState::update(float dt) {
        if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
            data->machine.addState(StateRef(new MainMenuState(data)), true);
        }
    }

    void SplashState::draw(float dt) {
        data->window.clear();
        data->window.draw(background);
        data->window.display();
    }
}