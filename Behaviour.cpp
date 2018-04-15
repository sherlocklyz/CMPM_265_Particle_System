#include <math.h>
#include "Behaviour.h"
#include "Particle.h"

float Uniform::behave(float f)
{
	return 1;
}

float LinearUp::behave(float f)
{
	return f;
}

float LinearDown::behave(float f)
{
	return 1 - f;
}

float EaseInQuad::behave(float f)
{
	return f * f;
}

float BackEaseIn::behave(float f)
{
	float PI = 3.1415926f;
	return f * f * f - f * sin(f * PI);
}

float EaseOutCube::behave(float f)
{
	return (f - 1)*(f - 1)*(f - 1) + 1;
}

float CosDown::behave(float f)
{
	float PI = 3.1415926f;
	return cosf(PI / 2 * f);
}