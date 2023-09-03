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
        texPtr->setSmooth(true);
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

void Engine::Data::loadShaders() {
    if (!sf::Shader::isAvailable()) {
       std::cout << "Shaders are not supported on this system." << std::endl;
       return;
    }

    struct stat sb;
    if (stat(shaderPath.c_str(), &sb) != 0){
        std::cout << "Data: Can't find shaders directory!" << std::endl;
        return;
    }

    std::cout << "Data: Found shaders directory, processing..." << std::endl;

    for (const auto & entry : std::filesystem::directory_iterator(shaderPath)){
        sf::Shader *shaderPtr = new sf::Shader;
        std::string extension = entry.path().extension().string();
        if (extension == "vert")
            shaderPtr->loadFromFile(entry.path().string(), sf::Shader::Vertex);
        if (extension == "frag")
            shaderPtr->loadFromFile(entry.path().string(), sf::Shader::Fragment);
        std::pair<std::basic_string<char>, sf::Shader*> pair;
        pair.first = std::filesystem::path(entry.path()).filename().string();
        pair.second = shaderPtr;
        shaders_.push_back(pair);

        std::cout << "Data: Loaded shader -> " << pair.first << std::endl;
    }

    std::cout << "Data: Shader loading finished, total -> " << std::to_string(shaders_.size()) << std::endl;
}

void Engine::Data::loadResources() {
    loadTextures();
    loadFonts();
    loadShaders();
}

sf::Texture* Engine::Data::getTexture(const std::string& name) {
    for (int i = 0; i < textures_.size(); i++){
        if (textures_[i].first == name)
            return &textures_[i].second;
    }
    return nullptr;
}

sf::Font* Engine::Data::getFont(const std::string& name){
    for (int i = 0; i < fonts_.size(); i++){
        if (fonts_[i].first == name)
            return &fonts_[i].second;
    }
    return nullptr;
}

sf::Shader* Engine::Data::getShader(const std::string& name){
    for (int i = 0; i < shaders_.size(); i++){
        if (shaders_[i].first == name)
            return shaders_[i].second;
    }
    return nullptr;
}

