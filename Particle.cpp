#include "Particle.h"
#include "Behaviour.h"
#include <vector>

Particle::Particle()
{

}

Particle::Particle(float pos_x, float pos_y, float vel_end, float lifetime, float angle, float size, sf::Texture& tex)
{
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->vel_end= vel_end;
	this->lifetime = lifetime;
	this->angle = angle;
	this->size = size;

	time = 0.0f;

	shape = new sf::RectangleShape;
	shape->setSize(sf::Vector2f(size, size));
	shape->setOrigin(sf::Vector2f(size / 2, size / 2));
	shape->setPosition(sf::Vector2f(pos_x, pos_y));
	shape->setTexture(&tex);
	//shape->setFillColor(sf::Color::White);

}

Particle::~Particle()
{
	delete shape;
	shape = nullptr;
}

void Particle::update()
{
	time += 1.0f / 60.0f;
	sf::Vector2f pos = shape->getPosition();
	pos.x += vel;
	pos.y += vel;
	shape->setPosition(pos);
}

void Particle::draw(sf::RenderWindow& window)
{
	window.draw(*shape);
}

