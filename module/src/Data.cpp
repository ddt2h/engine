#include "Data.hpp"

Engine::Data::Data() {
    //temp
    AllocConsole();
    freopen("conin$","r",stdin);
    freopen("conout$","w",stdout);
    freopen("conout$","w",stderr);
}

void Engine::Data::loadTextures() {
    struct stat sb;
    if (stat(texturesPath.c_str(), &sb) != 0){
        std::cout << "Data: Can't find textures directory!" << std::endl;
        return;
    }

    std::cout << "Data: Found textures directory, processing..." << std::endl;

    for (const auto & entry : std::filesystem::directory_iterator(texturesPath)){
        sf::Texture *texPtr = new sf::Texture;
        texPtr->loadFromFile(entry.path().string());
        std::pair<std::string, sf::Texture> pair;
        pair.first = std::filesystem::path(entry.path()).filename().string();
        pair.second = *texPtr;
        textures_.push_back(pair);

        std::cout << "Data: Loaded texture -> " << pair.first << std::endl;
    }

    std::cout << "Data: Texture loading finished, total -> " << std::to_string(textures_.size()) << std::endl;
}

void Engine::Data::loadFonts() {
    struct stat sb;
    if (stat(fontsPath.c_str(), &sb) != 0){
        std::cout << "Data: Can't find fonts directory!" << std::endl;
        return;
    }

    std::cout << "Data: Found fonts directory, processing..." << std::endl;

    for (const auto & entry : std::filesystem::directory_iterator(fontsPath)){
        sf::Font *fntPtr = new sf::Font;
        fntPtr->loadFromFile(entry.path().string());
        std::pair<std::string, sf::Font> pair;
        pair.first = std::filesystem::path(entry.path()).filename().string();
        pair.second = *fntPtr;
        fonts_.push_back(pair);

        std::cout << "Data: Loaded font -> " << pair.first << std::endl;
    }

    std::cout << "Data: Font loading finished, total -> " << std::to_string(fonts_.size()) << std::endl;
}

void Engine::Data::loadResources() {
    loadTextures();
    loadFonts();
}

sf::Texture* Engine::Data::getTexture(const std::string& name) {
    for (int i = 0; i < textures_.size(); i++){
        if (textures_[i].first == name)
            return &textures_[i].second;
    }
    return nullptr;
}

