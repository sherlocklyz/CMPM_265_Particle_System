#pragma once

class Particle;

class Behaviour
{
public:
	virtual float behave(float f) { return 0; };
};

class Uniform : public Behaviour
{
public:
	virtual float behave(float f);
};

class LinearUp : public Behaviour
{
public:
	virtual float behave(float f);
};

class LinearDown : public Behaviour
{
public:
	virtual float behave(float f);
};

class EaseInQuad : public Behaviour
{
public:
	virtual float behave(float f);
}; 

class BackEaseIn : public Behaviour
{
public:
	virtual float behave(float f);
};

class EaseOutCube : public Behaviour
{
public:
	virtual float behave(float f);
};


class CosDown : public Behaviour
{
public:
	virtual float behave(float f);
};