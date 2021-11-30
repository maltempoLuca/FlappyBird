//
// Created by Luca Maltempo on 30/11/21.
//

#include "../Headers/HUD.h"

namespace Maltempo {

    HUD::HUD(const GameDataRef& data) : data(data) {
        scoreText.setFont(data->assetManager.getFont("Flappy Font"));

        scoreText.setString("0");
        scoreText.setCharacterSize(SCORE_FONT_SIZE);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
        scoreText.setPosition(data->renderWindow.getSize().x / 2, data->renderWindow.getSize().y / 7);
    }

    void HUD::draw() {
        data->renderWindow.draw(scoreText);
    }

    void HUD::updateScore(int score) {
        scoreText.setString(std::to_string(score));
    }
}