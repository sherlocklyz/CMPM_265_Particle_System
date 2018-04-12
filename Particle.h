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
	Particle(float pos_x, float pos_y, float vel_end, float lifetime, float angle, float size, sf::Texture& tex);
	~Particle();

	void update();
	void draw(sf::RenderWindow& window);

	float pos_x;
	float pos_y;
	float vel_end;
	float vel;
	float angle;
	float size;
	float lifetime;
	float time;
	
	sf::RectangleShape* shape;
	};