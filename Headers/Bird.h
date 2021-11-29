//
// Created by Luca Maltempo on 28/11/21.
//

#pragma once

#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>

namespace Maltempo {


    class Bird {
    public:
        explicit Bird(const GameDataRef &data);

        void draw();

        void animate(float dt);

        void update(float dt);

        void tap();

    private:
        GameDataRef data;
        sf::Sprite birdSprite;
        std::vector<sf::Texture> animationFrames;
        unsigned int animationIterator;
        sf::Clock animationClock;
        sf::Clock movementClock;
        int birdState;
        float rotation;
    };

}