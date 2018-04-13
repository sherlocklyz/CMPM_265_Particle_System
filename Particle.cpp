#include "Particle.h"
#include "Behaviour.h"
#include <vector>
#include <math.h>

Particle::Particle()
{

}

Particle::Particle(float pos_x, float pos_y, float vel_end, float lifetime, float angle, float size, Behaviour* b, sf::Texture& tex)
{
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->vel_end= vel_end;
	this->lifetime = lifetime;
	this->angle = angle;
	this->size = size;
	this->b = b;

	time = 0.0f;

	shape = new sf::RectangleShape;
	shape->setSize(sf::Vector2f(size, size));
	shape->setOrigin(sf::Vector2f(size / 2, size / 2));
	shape->setPosition(sf::Vector2f(pos_x, pos_y));
	shape->setTexture(&tex);

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
	vel = vel_end * this->b->behave(this->time / this->lifetime);
	pos.x += vel * cosf(this->angle * 3.1415926f / 180.0f);
	pos.y += vel * sinf(this->angle * 3.1415926f / 180.0f);
	shape->setPosition(pos);
}

void Particle::draw(sf::RenderWindow& window)
{
	window.draw(*shape);
}

