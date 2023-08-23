#include "Mandelbrot.hpp"
#include <iostream>

Mandelbrot::Mandelbrot()
: m_isDrawn(false)
{
}

bool Mandelbrot::isDrawn()
{
    return(m_isDrawn);
}

void Mandelbrot::setDrawn(bool isDrawn)
{
    m_isDrawn = isDrawn;
}

void Mandelbrot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::CircleShape point;
    point.setRadius(1.2);
    point.setOrigin(1.2, 1.2);

    Complexe u(-2.f, 1.f);
    Complexe dx(0.003/2., 0.f);
    Complexe unity(1.f, 0.f);
    Complexe dy(0.f, -0.001);

    for(std::size_t i = 0; i < 2000; ++i)
    {
        for(std::size_t j = 0; j < 2000; ++j)
        {
            u = u + dx;
            point.setFillColor(colorLevel(u));
            point.setPosition(getCoordFromComplexeNum(u, target.getSize().x, target.getSize().y));
            target.draw(point);
        }

        u = u + dy + unity*(-u.getRe()-2.f);
    }
}

sf::Color Mandelbrot::colorLevel(Complexe z) const
{
    Complexe u(0.f, 0.f);

    for (std::size_t i = 0; i < 50; ++i)
    {
        u = u*u + z;
        if(u.getNormal() > 2.f)
        {
            if(i < 25)
            {
                return(sf::Color(255*i/25,0,0));
            }
            else 
            {
                return(sf::Color(255,255*i/49,255*i/49));
            }
        }
    }

    return(sf::Color(255,255,255));
}

sf::Vector2f Mandelbrot::getCoordFromComplexeNum(Complexe z, int win_x, int win_y) const
{
    sf::Vector2f resultat({win_x*(z.getRe()+2)/3, win_y*(z.getIm()+1)/2});
    return resultat;
}