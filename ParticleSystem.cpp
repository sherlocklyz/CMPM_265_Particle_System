#include "ParticleSystem.h"
#include "ParticleManager.h"
#include "Behaviour.h"
#include <stdio.h>

ParticleSystem::ParticleSystem()
{
	for (int i = 0; i < 2; i++)
	{
		switch (rand() % 3)
		{
		case 0:
			behaviour = new Uniform();
			break;
		case 1:
			behaviour = new EaseIn();
			break;
		case 2:
			behaviour = new EaseOut();
			break;
		}
		b.push_back(behaviour);
	}
	
	tex1.loadFromFile("Circle_Aura_05.png");
	tex2.loadFromFile("Crystal_03.png");


	ParticleManager* pm1 = new ParticleManager(300, 300, 3, 6, 1, 5, 0, 360, 20, 1000, b[0], tex1);
	pm.push_back(pm1);
	ParticleManager* pm2 = new ParticleManager(800, 500, 2, 4, 2, 6, 0, 180, 100, 200, b[1], tex2);
	pm.push_back(pm2);
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
	delete behaviour;
	behaviour = nullptr;
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