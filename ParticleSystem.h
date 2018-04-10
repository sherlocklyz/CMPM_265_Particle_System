#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void update_state();
	void render_frame(sf::RenderWindow& window);
};