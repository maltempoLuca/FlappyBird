//
// Created by Luca Maltempo on 28/11/21.
//

#pragma once

#include "DEFINITIONS.h"
#include "Game.h"

namespace Maltempo {


    class Bird {
    public:
        explicit Bird(const GameDataRef& data);

        void draw();

    private:
        GameDataRef data;
        sf::Sprite birdSprite;
    };

}