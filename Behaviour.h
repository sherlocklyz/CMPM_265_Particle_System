#pragma once

class Particle;

class Behaviour
{
public:
	virtual void behave(Particle* p) {};
};

class LinearMovement : public Behaviour
{
public:
	virtual void behave(Particle* p);
};

class CubeMovement : public Behaviour
{
public:
	virtual void behave(Particle* p);
};

class SinOutMovement : public Behaviour
{
public:
	virtual void behave(Particle* p);
};