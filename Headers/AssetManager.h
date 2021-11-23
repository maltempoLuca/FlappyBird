//
// Created by Luca Maltempo on 22/11/21.
//

#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

namespace Maltempo {

    class AssetManager {
    public:
        AssetManager() {}

        ~AssetManager() {};

        void loadTexture(std::string name, std::string fileName);

        sf::Texture &getTexture(std::string name);

        void loadFont(std::string name, std::string fileName);

        sf::Font &getFont(std::string name);

    private:
        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;
    };
}



