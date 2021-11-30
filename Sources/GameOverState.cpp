//
// Created by Luca Maltempo on 25/11/21.
//
#pragma once

#include<sstream>
#include "../Headers/GameOverState.h"
#include "../Headers/MainMenuState.h"
#include <iostream>
#include <fstream>

namespace Maltempo {

    GameOverState::GameOverState(GameDataRef data, int score) : data(data), score(score) {

    }

    void GameOverState::init() {
        std::ifstream readFile;
        readFile.open(HIGHSCORE_FILE_PATH);
        if (readFile.is_open()) {
            while (!readFile.eof()) {
                readFile >> highScore;
            }
            readFile.close();
        }

        std::ofstream writeFile(HIGHSCORE_FILE_PATH);
        if (writeFile.is_open()) {
            if (score > highScore) {
                highScore = score;
            }
            writeFile << highScore;
            writeFile.close();
        }

        std::cout << "Game Over State" << std::endl;
        data->assetManager.loadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        data->assetManager.loadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
        data->assetManager.loadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
        data->assetManager.loadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
        data->assetManager.loadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
        data->assetManager.loadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
        data->assetManager.loadTexture("Platinum Medal", PLATINUM_MEDAL_FILEPATH);
        background.setTexture(this->data->assetManager.getTexture("Game Over Background"));
        gameOverTitle.setTexture(this->data->assetManager.getTexture("Game Over Title"));
        gameOverContainer.setTexture(this->data->assetManager.getTexture("Game Over Body"));
        retryButton.setTexture(this->data->assetManager.getTexture("PlayButton"));

        gameOverContainer.setOrigin(gameOverContainer.getGlobalBounds().width / 2,
                                    gameOverContainer.getGlobalBounds().height / 1.5);
        gameOverContainer.setPosition(data->renderWindow.getSize().x / 2, data->renderWindow.getSize().y / 2);

        gameOverTitle.setOrigin(gameOverTitle.getGlobalBounds().width / 2,
                                gameOverTitle.getGlobalBounds().height / 2);
        gameOverTitle.setPosition(data->renderWindow.getSize().x / 2,
                                  gameOverContainer.getPosition().y -
                                  (gameOverContainer.getGlobalBounds().height * 1.15));


        retryButton.setPosition(data->renderWindow.getSize().x / 2 - retryButton.getGlobalBounds().width / 2,
                                gameOverContainer.getPosition().y + gameOverContainer.getGlobalBounds().height / 2);

        scoreText.setFont(data->assetManager.getFont("Flappy Font"));
        scoreText.setString(std::to_string(score));
        scoreText.setCharacterSize(SCORE_FONT_SIZE_GAME_OVER);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
        scoreText.setPosition(data->renderWindow.getSize().x / 10 * 7.25, data->renderWindow.getSize().y / 2.4);

        highScoreText.setFont(data->assetManager.getFont("Flappy Font"));
        highScoreText.setString(std::to_string(highScore));
        highScoreText.setCharacterSize(SCORE_FONT_SIZE_GAME_OVER);
        highScoreText.setFillColor(sf::Color::White);
        highScoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
        highScoreText.setPosition(data->renderWindow.getSize().x / 10 * 7.25, data->renderWindow.getSize().y / 1.95);

        if (score >= PLATINUM_MEDAL_SCORE) {
            medal.setTexture(data->assetManager.getTexture("Platinum Medal"));
        } else if (score >= GOLD_MEDAL_SCORE) {
            medal.setTexture(data->assetManager.getTexture("Gold Medal"));
        } else if (score >= SILVER_MEDAL_SCORE) {
            medal.setTexture(data->assetManager.getTexture("Silver Medal"));
        } else
            medal.setTexture(data->assetManager.getTexture("Bronze Medal"));
        medal.setPosition(data->renderWindow.getSize().x / 10 * 2.26, data->renderWindow.getSize().y / 2.40);


        data->renderWindow.setFramerateLimit(60);
    }

    void GameOverState::handleInput() {
        sf::Event event;
        while (data->renderWindow.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                data->renderWindow.close();
            }

            if (data->inputManager.isSpriteClicked(retryButton, sf::Mouse::Left, data->renderWindow)) {
                data->stateMachine.addState(StateRef(new GameState(data)), true);
            }
        }
    }

    void GameOverState::update(float dt) {
    }

    void GameOverState::draw(float dt) {
        data->renderWindow.clear();
        data->renderWindow.draw(background);
        data->renderWindow.draw(gameOverTitle);
        data->renderWindow.draw(gameOverContainer);
        data->renderWindow.draw(retryButton);
        data->renderWindow.draw(scoreText);
        data->renderWindow.draw(highScoreText);
        data->renderWindow.draw(medal);
        data->renderWindow.display();

    }
}