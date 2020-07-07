#pragma once
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include <sstream>
#include <fstream>

class color_loader {
public:
    enum Purpose
    {
        background, background2, text, texthighlight, gui, guihighlight, gui_back ,good, bad
    };
    void load(std::string path);
    sf::Color getColor(unsigned index);
    sf::Color getColor(Purpose purp);
private:
    std::vector<sf::Color> m_colors;
};


