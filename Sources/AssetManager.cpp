//
// Created by Luca Maltempo on 22/11/21.
//

#include "../Headers/AssetManager.h"

namespace Maltempo {
    //TODO:: unloadTexture method to unload texture when we move to a new states that dont rquire some textures. free space.

    void AssetManager::loadTexture(std::string name, std::string fileName) {
        sf::Texture tex;
        if (tex.loadFromFile(fileName)) {    //TODO:: ERRORE QUI!
            this->textures[name] = tex;
        }
    }

    sf::Texture &AssetManager::getTexture(std::string name) {
        return this->textures.at(name);
    }

    void AssetManager::loadFont(std::string name, std::string fileName) {
        sf::Font font;
        if (font.loadFromFile(fileName)) {
            this->fonts[name] = font;
        }
    }

    sf::Font &AssetManager::getFont(std::string name) {
        return this->fonts.at(name);
    }
}
