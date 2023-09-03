#ifndef NFFSMODULE_DATA_HPP
#define NFFSMODULE_DATA_HPP

#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <windows.h>
namespace Engine{

    class Data{
    private:
        std::vector<std::pair<std::string, sf::Texture>> textures_;
        std::vector<std::pair<std::string, sf::Font>> fonts_;
        std::vector<std::pair<std::string, sf::Sound>> sounds_;
        std::vector<std::pair<std::string, sf::Shader*>> shaders_;

        std::string texturesPath = "textures";
        std::string fontsPath = "fonts";
        std::string soundsPath = "sounds";
        std::string shaderPath = "shaders";

        void loadTextures();
        void loadFonts();
        void loadSounds();
        void loadShaders();

    public:
        Data();

        void loadResources();

        sf::Texture* getTexture(const std::string& name);

        sf::Font* getFont(const std::string& name);

        sf::Shader* getShader(const std::string& name);
    };
}


#endif //NFFSMODULE_DATA_HPP
