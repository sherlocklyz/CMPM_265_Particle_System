#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class ParticleManager
{
public:
	ParticleManager();
	ParticleManager(float pos_x, float pos_y, float vel_min, float vel_max, 
					float lifetime_min, float lifetime_max, float angle_min, float angle_max);
	~ParticleManager();

	void update();
	void draw(sf::RenderWindow& window);

private:
	float pos_x;
	float pos_y;
	float vel_min;
	float vel_max;
	float lifetime_min;
	float lifetime_max;
	float angle_min;
	float angle_max;
};