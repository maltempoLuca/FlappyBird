//
// Created by Luca Maltempo on 22/11/21.
//

#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace Maltempo {
    struct GameData {
        StateMachine stateMachine;
        sf::RenderWindow renderWindow;
        AssetManager assetManager;
        InputManager inputManager;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
    public:
        Game(int width, int height, std::string title);

    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock clock;
        GameDataRef data = std::make_shared<GameData>();

        void run();
    };
}



