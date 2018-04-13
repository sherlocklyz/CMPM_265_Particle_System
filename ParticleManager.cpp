#include "ParticleManager.h"
#include "Particle.h"
#include "Behaviour.h"

ParticleManager::ParticleManager()
{

}

ParticleManager::ParticleManager(float pos_x, float pos_y, float vel_min, float vel_max, float lifetime_min, float lifetime_max, 
								 float angle_min, float angle_max, float rot_min, float rot_max, float size, float init_number, std::vector<Behaviour*> b, sf::Texture& tex)
{
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->vel_min = vel_min;
	this->vel_max = vel_max;
	this->lifetime_min = lifetime_min;
	this->lifetime_max = lifetime_max;
	this->angle_min = angle_min;
	this->angle_max = angle_max;
	this->rot_min = rot_min;
	this->rot_max = rot_max;
	this->size = size;
	this->init_number = init_number;
	this->b = b;
	this->tex = tex;

	for (int i = 0; i < this->init_number; i++)
	{
		float vel = rand() % ((int)(vel_max * 10) - (int)(vel_min * 10)) / 10.0f + vel_min;
		float lifetime = rand() % ((int)(lifetime_max * 10) - (int)(lifetime_min * 10)) / 10.0f + lifetime_min;
		float angle = rand() % ((int)(angle_max * 10) - (int)(angle_min * 10)) / 10.0f + angle_min;
		float rot = rand() % ((int)(rot_max * 10) - (int)(rot_min * 10)) / 10.0f + rot_min;

		Particle* particle = new Particle(pos_x, pos_y, vel, lifetime, angle, rot, size, b, tex);
		p.push_back(particle);
	}

	

}

ParticleManager::~ParticleManager()
{
	for (int i = 0; i < p.size(); i++)
	{
		Particle* temp = p[i];
		p.erase(p.begin() + i);
		delete temp;
		temp = nullptr;
	}
}

void ParticleManager::update()
{
	add_particle();
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i]->time <= p[i]->lifetime)
		{
			p[i]->update();
		}
		else
		{
			reset(i);
		}
	}
}

void ParticleManager::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < p.size(); i++)
	{
		p[i]->draw(window);
	}
}

void ParticleManager::reset(int i)
{
	p[i]->time = 0.0f;
	p[i]->shape->setSize(sf::Vector2f(0, 0));
	p[i]->shape->setOrigin(sf::Vector2f(0, 0));
	p[i]->shape->setPosition(this->pos_x, this->pos_y);
	p[i]->vel_end = rand() % ((int)(vel_max * 10) - (int)(vel_min * 10)) / 10.0f + vel_min;
	p[i]->lifetime = rand() % ((int)(lifetime_max * 10) - (int)(lifetime_min * 10)) / 10.0f + lifetime_min;
	p[i]->angle = rand() % ((int)(angle_max * 10) - (int)(angle_min * 10)) / 10.0f + angle_min;
	p[i]->rot_end = rand() % ((int)(rot_max * 10) - (int)(rot_min * 10)) / 10.0f + rot_min;

}

void ParticleManager::add_particle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		float vel = rand() % ((int)(vel_max * 10) - (int)(vel_min * 10)) / 10.0f + vel_min;
		float lifetime = rand() % ((int)(lifetime_max * 10) - (int)(lifetime_min * 10)) / 10.0f + lifetime_min;
		float angle = rand() % ((int)(angle_max * 10) - (int)(angle_min * 10)) / 10.0f + angle_min;
		float rot = rand() % ((int)(rot_max * 10) - (int)(rot_min * 10)) / 10.0f + rot_min;

		Particle* particle = new Particle(pos_x, pos_y, vel, lifetime, angle, rot, size, b, tex);
		p.push_back(particle);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (p.size() >= 1)
		{
			int i = p.size() - 1;
			Particle* temp = p[i];
			p.erase(p.begin() + i);
			delete temp;
			temp = nullptr;
		}
	}
}