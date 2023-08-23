#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Mandelbrot.hpp"

class Engine
{
public :
	
	Engine();
	void run();
	
private :
	
	void processEvents();
	void update();
	void render();
	
private :
	
	sf::RenderWindow m_window;
	static const sf::Time m_timePerFrame;
	Mandelbrot m_mandelset;
};

#endif //ENGINE_HPP
