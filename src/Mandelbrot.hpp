#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include <SFML/Graphics.hpp>
#include "Complexe.hpp"

class Mandelbrot : public sf::Drawable
{
public :
    Mandelbrot();
    bool isDrawn();
    void setDrawn(bool);

private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    sf::Color colorLevel(Complexe z) const;
    sf::Vector2f getCoordFromComplexeNum(Complexe z, int win_x, int win_y) const;

private :
    bool m_isDrawn;
};

#endif //MANDELBROT_HPP