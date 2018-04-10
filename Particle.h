#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class Particle
{
public:
	Particle();
	Particle(float pos_x, float pos_y, float vel, float lifetime, float angle);
	~Particle();

	void update();
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape* shape;

	float pos_x;
	float pos_y;
	float vel;
	float lifetime;
	float angle;
};