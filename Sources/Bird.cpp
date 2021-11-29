//
// Created by Luca Maltempo on 28/11/21.
//

#include "../Headers/Bird.h"

namespace Maltempo {

    Bird::Bird(const GameDataRef &data) : data(data) {
        animationIterator = 0;
        animationFrames.push_back(data->assets.getTexture("Bird Frame 1"));
        animationFrames.push_back(data->assets.getTexture("Bird Frame 2"));
        animationFrames.push_back(data->assets.getTexture("Bird Frame 3"));
        animationFrames.push_back(data->assets.getTexture("Bird Frame 4"));

        birdSprite.setTexture(animationFrames.at(animationIterator));
        birdSprite.setPosition((data->window.getSize().x / 4) - (birdSprite.getGlobalBounds().width / 2),
                               (data->window.getSize().y / 2) - (birdSprite.getGlobalBounds().height / 2));
        birdState = BIRD_STATE_STILL;

        sf::Vector2f origin = sf::Vector2f(birdSprite.getGlobalBounds().width / 2,
                                           birdSprite.getGlobalBounds().height / 2);
        birdSprite.setOrigin(origin);

        rotation = 0;
    }

    void Bird::draw() {
        data->window.draw(birdSprite);
    }

    void Bird::animate(float dt) {
        if (animationClock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / animationFrames.size()) {
            animationIterator = (animationIterator + 1) % animationFrames.size();

            birdSprite.setTexture(animationFrames.at(animationIterator));
            animationClock.restart();
        }
    }

    void Bird::update(float dt) {
        if (birdState == BIRD_STATE_FALLING) {
            birdSprite.move(0, (GRAVITY * dt));
            rotation += ROTATION_SPEED * dt;

            if (rotation > 30.0f) {
                rotation = 30.0f;
            }

            birdSprite.setRotation(rotation);

        } else if (birdState == BIRD_STATE_FLYING) {
            birdSprite.move(0, -(FLYING_SPEED * dt));
            rotation -= ROTATION_SPEED * dt;

            if (rotation < -25.0f) {
                rotation = -25.0f;
            }

            birdSprite.setRotation(rotation);
        }

        if (movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
            birdState = BIRD_STATE_FALLING;
            movementClock.restart();
        }
    }

    void Bird::tap() {
        movementClock.restart();
        birdState = BIRD_STATE_FLYING;
    }

}
