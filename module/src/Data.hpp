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
class Data{
private:
    std::vector<std::pair<std::string, sf::Texture>> textures_;
    std::vector<std::pair<std::string, sf::Font>> fonts_;
    std::vector<std::pair<std::string, sf::Sound>> sounds_;

    std::string texturesPath = "textures";
    std::string fontsPath = "fonts";
    std::string soundsPath = "sounds";

    void loadTextures();
    void loadFonts();
    void loadSounds();

public:
    Data();

    void loadResources();
};

#endif //NFFSMODULE_DATA_HPP
