#include "ParticleSystem.h"
#include "ParticleManager.h"
#include "Behaviour.h"

ParticleSystem::ParticleSystem()
{
	m1 = new LinearMovement();
	m2 = new CubeMovement();
	m3 = new SinOutMovement();
	int i = rand() % 3;
	switch (i)
	{
	case 0:
		this->b.push_back(m1);
		break;
	case 1:
		this->b.push_back(m2);
		break;
	case 2:
		this->b.push_back(m3);
		break;
	}
	
	tex1.loadFromFile("Circle_Aura_05.png");
	tex2.loadFromFile("Crystal_03.png");


	ParticleManager* particle_manager = new ParticleManager(300, 300, 3, 6, 3, 5, -30, 30, 10, b, tex1);
	pm.push_back(particle_manager);
}

ParticleSystem::~ParticleSystem()
{
	for (int i = 0; i < pm.size(); i++)
	{
		ParticleManager* temp = pm[i];
		pm.erase(pm.begin() + i);
		delete temp;
		temp = nullptr;
	}
	delete m1;
	m1 = nullptr;
	delete m2;
	m2 = nullptr;
	delete m3;
	m3 = nullptr;
}

void ParticleSystem::update_state()
{
	for (int i = 0; i < pm.size(); i++)
	{
		pm[i]->update();
	}
}

void ParticleSystem::render_frame(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	for (int i = 0; i < pm.size(); i++)
	{
		pm[i]->draw(window);
	}
}