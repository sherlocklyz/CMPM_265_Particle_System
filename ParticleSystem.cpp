#include "ParticleSystem.h"
#include "ParticleManager.h"
#include "Behaviour.h"
#include <stdio.h>

ParticleSystem::ParticleSystem()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (rand() % 5)
			{
			case 0:
				b[j] = new Uniform();
				break;
			case 1:
				b[j] = new LinearUp();
				break;
			case 2:
				b[j] = new LinearDown();
				break;
			case 3:
				b[j] = new EaseIn();
				break;
			case 4:
				b[j] = new EaseOut();
				break;
			}
			b_collection[i].push_back(b[j]);
		}
	}

	tex1.loadFromFile("Circle_Aura_05.png");
	tex2.loadFromFile("Crystal_03.png");


	ParticleManager* pm1 = new ParticleManager(300, 200, 2, 6, 3, 5, -35, 10, 0, 1080, 80, 300, b_collection[0], tex1);
	pm.push_back(pm1);
	ParticleManager* pm2 = new ParticleManager(850, 350, 2, 4, 2, 6, 60, 120, -1080, 0, 60, 200, b_collection[1], tex2);
	pm.push_back(pm2);
	ParticleManager* pm3 = new ParticleManager(250, 700, 2, 4, 2, 4, 220, 290, -720, 720, 80, 300, b_collection[2], tex2);
	pm.push_back(pm3);
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
	for (int i = 0; i < 3; i++)
	{
		delete b[i];
		b[i] = nullptr;
	}
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