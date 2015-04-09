#pragma once
#include "Emitter.h"

class Sphere : public Emitter
{
public:
	Sphere();
	virtual void Particle_Spawn(Particle& particle);
	 void Render();

	float MIN_RAD;
	float MAX_RAD;
	float MIN_Incline;
	float MAX_Incline;
	float MIN_Azi;
	float MAX_Azi;
	float MIN_Speed;
	float MAX_Speed;
	float MIN_Lifetime;
	float MAX_Lifetime;

	glm::vec3 Origin;

	void SphereRENDER(glm::vec4 color, float Radius);
};

