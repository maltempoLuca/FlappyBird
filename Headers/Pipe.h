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
        explicit Pipe(const GameDataRef& data);

        void spawnBottomPipe();

        void spawnTopPipe();

        void spawnScoringPipe();

        void movePipes(float dt);

        void drawPipes();

        void randomisePipeOffset();

        [[nodiscard]] const std::vector<sf::Sprite> &getPipeSprites() const;
        [[nodiscard]] const std::vector<sf::Sprite> &getScoringPipesSprites() const;

        [[maybe_unused]] std::vector<bool>  &getIsBeenHitScore();

    private:
        GameDataRef data;
        std::vector<sf::Sprite> pipeSprites;
        std::vector<sf::Sprite> scoringSprites;
        std::vector<bool> hitScore;


        float landHeight;
        float pipeSpawnYOffset;

        std::random_device rd;
        std::default_random_engine defEngine = std::default_random_engine(rd());
        std::uniform_real_distribution<float> floatDistro = std::uniform_real_distribution<float>(0, 1);
    };
}


