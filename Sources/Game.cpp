//
// Created by Luca Maltempo on 22/11/21.
//

#include "../Headers/Game.h"
#include "../Headers/SplashState.h"

namespace Maltempo {
    Game::Game(int width, int height, std::string title) {
        data->renderWindow.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        data->stateMachine.addState(StateRef(new SplashState(this->data)));

        this->run();
    }

    void Game::run() {
        float newTime, frameTime, interpolation;
        float currentTime = this->clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->data->renderWindow.isOpen()) {
            this->data->stateMachine.processStateChanges();

            newTime = this->clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;
            while (accumulator >= dt) {
                this->data->stateMachine.getActiveState()->handleInput();
                this->data->stateMachine.getActiveState()->update(dt);

                accumulator -= dt;
            }
            interpolation = accumulator / dt;
            this->data->stateMachine.getActiveState()->draw(interpolation);
        }
    }
}
