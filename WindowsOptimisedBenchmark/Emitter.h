#pragma once
#include "Particle.h"

class Emitter
{
public:
	virtual ~Emitter() {}
	virtual void Particle_Spawn(Particle& particle) = 0;

	virtual void Render() {}
};

