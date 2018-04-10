#include "Particle.h"

Particle::Particle()
{

}

Particle::Particle(float pos_x, float pos_y, float vel_x, float vel_y, float lifetime, float angle)
{
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->vel_x = vel_x;
	this->vel_y = vel_y;
	this->lifetime = lifetime;
	this->angle = angle;

	shape = new sf::RectangleShape;
	
}

Particle::~Particle()
{
	delete shape;
	shape = nullptr;
}

void Particle::update()
{

}

void Particle::draw(sf::RenderWindow& window)
{

}