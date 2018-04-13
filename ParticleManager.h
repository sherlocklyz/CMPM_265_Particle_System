#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class Particle;
class Behaviour;

class ParticleManager
{
public:
	ParticleManager();
	ParticleManager(float pos_x, float pos_y, float vel_min, float vel_max, float lifetime_min, float lifetime_max, 
					float angle_min, float angle_max, float size, float init_number, Behaviour* b, sf::Texture& tex);
	~ParticleManager();

	void update();
	void draw(sf::RenderWindow& window);


	float pos_x;
	float pos_y;
	float vel_min;
	float vel_max;
	float lifetime_min;
	float lifetime_max;
	float angle_min;
	float angle_max;
	float init_number;
	float size;

private:
	std::vector<Particle*> p;
	Behaviour* b;

		void reset(int i);
};