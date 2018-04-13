#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "Behaviour.h"

class ParticleManager;


class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void update_state();
	void render_frame(sf::RenderWindow& window);

private:
	std::vector<ParticleManager*> pm;

	Behaviour* behaviour;
	std::vector<Behaviour*> b;


	sf::Texture tex1;
	sf::Texture tex2;
};
