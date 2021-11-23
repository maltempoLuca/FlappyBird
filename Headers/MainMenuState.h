//
// Created by Luca Maltempo on 23/11/21.
//



#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Maltempo {
    class MainMenuState : public State {
    public:
        explicit MainMenuState(GameDataRef data);

        void init() override;

        void handleInput() override;

        void update(float dt) override;

        void draw(float dt) override;

    private:
        GameDataRef data;
        sf::Sprite background;
        sf::Sprite title;
        sf::Sprite playButton;

    };

}

