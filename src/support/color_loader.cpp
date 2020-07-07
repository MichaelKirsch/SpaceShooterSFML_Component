#include "color_loader.h"

void color_loader::load(std::string path) {

    std::ifstream file(path);
    if(!file.is_open())
        throw std::runtime_error(path+" is not existing or cant be opened");
    std::string s = "";
    std::string delimiter = "-";
    m_colors.clear();
    getline (file,s);

    file.close();

    size_t pos = 0;
    std::string token;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        int red=0;
        int green =0;
        int blue=0;

        std::stringstream ss;
        ss << std::hex<< token.substr(0,2);
        ss>>red;
        ss.clear();
        ss << std::hex<< token.substr(2,2);
        ss>>green;
        ss.clear();
        ss << std::hex<< token.substr(4,2);
        ss>>blue;

        m_colors.emplace_back(sf::Color(red,green,blue,255));

        s.erase(0, pos + delimiter.length());
    }
}

sf::Color color_loader::getColor(unsigned index) {
    if(index>m_colors.size())
        throw std::runtime_error("color requested out of range!");
    return m_colors[index];
}

sf::Color color_loader::getColor(color_loader::Purpose purp) {
    if(purp>m_colors.size())
        throw std::runtime_error("color requested out of range!");
    return m_colors[purp];
}
