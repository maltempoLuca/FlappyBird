//
// Created by Luca Maltempo on 30/11/21.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"
#include "iostream"

namespace Maltempo {

    class Flash {
    public:

        explicit Flash(GameDataRef data);

        void show(float dt);

        void draw();

    private:
        GameDataRef data;
        sf::RectangleShape shape;
        bool flashOn;
    };

}


