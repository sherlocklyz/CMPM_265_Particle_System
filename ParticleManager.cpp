#include "ParticleManager.h"
#include "Particle.h"
#include "Behaviour.h"

ParticleManager::ParticleManager()
{

}

ParticleManager::ParticleManager(float pos_x, float pos_y, float vel_min, float vel_max, float lifetime_min, float lifetime_max, 
								 float angle_min, float angle_max, float size, float init_number, std::vector<Behaviour*> b, sf::Texture& tex)
{
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->vel_min = vel_min;
	this->vel_max = vel_max;
	this->lifetime_min = lifetime_min;
	this->lifetime_max = lifetime_max;
	this->angle_min = angle_min;
	this->angle_max = angle_max;
	this->size = size;
	this->init_number = init_number;
	this->b = b;

	for (int i = 0; i < this->init_number; i++)
	{
		float vel = rand() % ((int)(vel_max * 10) - (int)(vel_min * 10)) / 10.0f + vel_min;
		float lifetime = rand() % ((int)(lifetime_max * 10) - (int)(lifetime_min * 10)) / 10.0f + lifetime_min;
		float angle = rand() % ((int)(angle_max * 10) - (int)(angle_min * 10)) / 10.0f + angle_min;

		Particle* particle = new Particle(pos_x, pos_y, vel, lifetime, angle, size, tex);
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
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i]->time <= p[i]->lifetime)
		{
			for (int j = 0; j < b.size(); j++)
			{
				b[j]->behave(p[i]);
			}
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
	p[i]->shape->setPosition(this->pos_x, this->pos_y);
	p[i]->vel_end = rand() % ((int)(vel_max * 10) - (int)(vel_min * 10)) / 10.0f + vel_min;
	p[i]->lifetime = rand() % ((int)(lifetime_max * 10) - (int)(lifetime_min * 10)) / 10.0f + lifetime_min;
	p[i]->angle = rand() % ((int)(angle_max * 10) - (int)(angle_min * 10)) / 10.0f + angle_min;
	p[i]->size = this->size;
	p[i]->time = 0.0f;
}