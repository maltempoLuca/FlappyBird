//
// Created by Luca Maltempo on 26/11/21.
//

#include "../Headers/Pipe.h"
#include "../Headers/DEFINITIONS.h"


//TODO:: gestisci attraverso una struct i pipes + boolean.
namespace Maltempo {

    Pipe::Pipe(const GameDataRef &data) : data(data), landHeight(data->assetManager.getTexture("Land").getSize().y),
                                          pipeSpawnYOffset(0) {
    }

    void Pipe::drawPipes() {
        for (const auto &pipeSprite: pipeSprites) {
            data->renderWindow.draw(pipeSprite);
        }
    }

    void Pipe::spawnBottomPipe() {
        sf::Sprite sprite(data->assetManager.getTexture("Pipe Up"));
        sprite.setPosition(data->renderWindow.getSize().x,
                           data->renderWindow.getSize().y - sprite.getGlobalBounds().height - pipeSpawnYOffset);
        pipeSprites.push_back(sprite);
    }

    void Pipe::spawnTopPipe() {
        sf::Sprite sprite(data->assetManager.getTexture("Pipe Down"));
        sprite.setPosition(data->renderWindow.getSize().x, -pipeSpawnYOffset);
        pipeSprites.push_back(sprite);
    }

    void Pipe::spawnScoringPipe() {
        sf::Sprite sprite(data->assetManager.getTexture("Scoring Pipe"));
        sprite.setPosition(data->renderWindow.getSize().x + (sprite.getGlobalBounds().width / 2), 0);
        sprite.setColor(sf::Color(0, 0, 0, 0));

        scoringSprites.push_back(sprite);
        hitScore.push_back(false);
    }

    void Pipe::movePipes(float dt) {
        for (int i = 0; i < pipeSprites.size(); i++) {
            float movement = PIPE_MOVEMENT_SPEED * dt;
            pipeSprites.at(i).move(-movement, 0);
        }

        for (int i = 0; i < pipeSprites.size(); i++) {
            if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) {
                pipeSprites.erase(pipeSprites.begin() + i);
            }
        }

        for (int i = 0; i < scoringSprites.size(); i++) {
            float movement = PIPE_MOVEMENT_SPEED * dt;
            scoringSprites.at(i).move(-movement, 0);
            if (scoringSprites.at(i).getPosition().x <
                0 - scoringSprites.at(i).getGlobalBounds().width - (scoringSprites.at(i).getGlobalBounds().width / 2)) {
                scoringSprites.erase(scoringSprites.begin() + i);
                hitScore.erase(hitScore.begin() + i);
            }
        }
    }

    void Pipe::randomisePipeOffset() {
        pipeSpawnYOffset = (floatDistro(defEngine) * (float) (landHeight + 1.0));
    }

    const std::vector<sf::Sprite> &Pipe::getPipeSprites() const {
        return pipeSprites;
    }

    const std::vector<sf::Sprite> &Pipe::getScoringPipesSprites() const {
        return scoringSprites;
    }

    std::vector<bool> &Pipe::getIsBeenHitScore() {
        return hitScore;
    }
}