#include <math.h>
#include "Behaviour.h"
#include "Particle.h"

void LinearMovement::behave(Particle* p)
{
	p->vel = p->vel_end;
}

void CubeMovement::behave(Particle* p)
{
	float r = p->time / p->lifetime;
	r = r * r;
	p->vel = p->vel_end * r;
}

void SinOutMovement::behave(Particle* p)
{
	float PI = 3.1415926f;
	float r = p->time / p->lifetime;
	r = cosf(PI / 2 * r);
	p->vel = p->vel_end * r;
}