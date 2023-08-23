#include "Engine.hpp"
#include <iostream>

const sf::Time Engine::m_timePerFrame = sf::seconds(1.f/60.f);

Engine::Engine()
: m_window(sf::VideoMode(3800, 2400), "Mandelbrot")
{
}

void Engine::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		
		while (timeSinceLastUpdate > m_timePerFrame)
		{
			timeSinceLastUpdate -= m_timePerFrame;
			update();
		}

		render();
	}
}

void Engine::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			m_window.close();
	}
}

void Engine::update()
{
}

void Engine::render()
{
	if(!m_mandelset.isDrawn())
	{
		m_window.clear();
		m_window.draw(m_mandelset);
		m_window.display();
		m_mandelset.setDrawn(true);
	}
}
