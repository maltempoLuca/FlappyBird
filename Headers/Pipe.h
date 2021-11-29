//
// Created by Luca Maltempo on 26/11/21.
//

#pragma once

#include "Game.h"
#include <vector>
#include "random"
#include <ctime>

namespace Maltempo {

    class Pipe {
    public:
        explicit Pipe(GameDataRef data);

        void spawnBottomPipe();

        void spawnTopPipe();

        void movePipes(float dt);

        void drawPipes();

        void randomisePipeOffset();

        const std::vector<sf::Sprite> &getPipeSprites() const;

        void setPipeSprites(const std::vector<sf::Sprite> &pipeSprites);

    private:
        GameDataRef data;
        std::vector<sf::Sprite> pipeSprites;

        float landHeight;
        float pipeSpawnYOffset;

        std::random_device rd;
        std::default_random_engine defEngine = std::default_random_engine(rd());
        std::uniform_real_distribution<float> floatDistro = std::uniform_real_distribution<float>(0, 1);
    };
}


