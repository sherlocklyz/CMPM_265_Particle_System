#include "ParticleManager.h"

ParticleManager::ParticleManager()
{

}

ParticleManager::ParticleManager(float pos_x, float pos_y, float vel_min, float vel_max, float lifetime_min, float lifetime_max, float angle_min, float angle_max) 
{
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->vel_min = vel_min;
	this->vel_max = vel_max;
	this->lifetime_min = lifetime_min;
	this->lifetime_max = lifetime_max;
	this->angle_min = angle_min;
	this->angle_max = angle_max;

}

ParticleManager::~ParticleManager()
{

}

void ParticleManager::update()
{

}

void ParticleManager::draw(sf::RenderWindow& window)
{

}