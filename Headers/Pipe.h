//
// Created by Luca Maltempo on 26/11/21.
//

#pragma once

#include "Game.h"
#include <vector>

namespace Maltempo {

    class Pipe {
    public:
        explicit Pipe(GameDataRef data);
        void spawnBottomPipe();
        void spawnTopPipe();
        void movePipes(float dt);
        void drawPipes();

    private:
        GameDataRef data;
        std::vector<sf::Sprite> pipeSprites;
    };
}


