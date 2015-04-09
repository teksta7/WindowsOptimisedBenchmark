#include "stdafx.h"
#include "ParticleData.h"
#include "Emitter.h"
#include "CustomCamera.h"
#include <iostream>

using namespace std;


ParticleData::ParticleData(unsigned int Particle_Count)
	:
	BenchmarkCAM(NULL),
	ParticleEMIITER( NULL ),
	TransformationMatrix(1),
	DefaultCOLOR(1,1,1,1),
	Force(0, -9.81f, 0)
{
	BufferResize(Particle_Count);
}

void ParticleData::EmitterSpawn(Emitter* emitt)
{
	ParticleEMIITER = emitt;
}

void ParticleData::CameraSetup(CustomCamera* CAM)
{
	BenchmarkCAM = CAM;
}

void ParticleData::Initialise_RAD_Particles()
{
	for (unsigned int i = 0; i < ParticleBUFFER.size(); ++i)
	{
		RandomParticles(ParticleBUFFER[i]);
	}
}

void ParticleData::EmitSingleParticle(Particle& instance)
{
	assert(ParticleEMIITER != NULL);
	ParticleEMIITER->Particle_Spawn(instance);
}

void ParticleData::ParticleSpawn()
{
	if (ParticleEMIITER == NULL)
	{
		Initialise_RAD_Particles();
	}
	else
	{
		for (unsigned int i = 0; i < ParticleBUFFER.size(); ++i)
		{
			EmitSingleParticle(ParticleBUFFER[i]);
		}

	}
}

void ParticleData::RandomParticles(Particle& instance)
{
	float X = ((rand() / (float)RAND_MAX) * 2.0f) - 1.0f;
	float Y = ((rand() / (float)RAND_MAX) * 2.0f) - 1.0f;
	float Z = ((rand() / (float)RAND_MAX) * 2.0f) - 1.0f;

	instance.P_age = 0.0f;
	//instance.P_Lifetime = (rand() / (float)RAND_MAX *(2));
	instance.P_Lifetime = 5.0f;
		
		
	glm::vec3 unitV = glm::normalize(glm::vec3(X, Y, Z));
		
	instance.ParticlePoint = unitV * 1.0f;
	instance.Speed = unitV * 10.0f;

	}
/*
void ParticleData::ParticleSpawn(Particle& instance)
{
	if (ParticleEMIITER == NULL)
	{
		
		RandomParticles(instance);
	}
	else
	{
		for (unsigned int i = 0; i < ParticleBUFFER.size(); ++i)
		{
			assert(ParticleEMIITER != NULL);
			ParticleEMIITER->Particle_Spawn(instance);
		}
	}
}
*/
void ParticleData::CreateVertexBUFFER()
{
	std::cout << "worked";
	const glm::vec3 X(0.5, 0, 0);
	const glm::vec3 Y(0, 0.5, 0);
	const glm::vec3 Z(0, 0, 1.0);

	glm::quat CAMrotation;

	if (BenchmarkCAM != NULL)
	{
		CAMrotation = glm::quat(glm::radians(BenchmarkCAM->getNEWrotation()));
	}

	vertexBUFFER.resize(ParticleBUFFER.size() * 4, vertex());

	for (unsigned int i = 0; i < ParticleBUFFER.size(); ++i)
	{
		Particle& instance = ParticleBUFFER[i];
		
		unsigned int v_INDEX = i * 4;
		vertex& vertex1 = vertexBUFFER[v_INDEX + 0];
		vertex& vertex2 = vertexBUFFER[v_INDEX + 1];
		vertex& vertex3 = vertexBUFFER[v_INDEX + 2];
		vertex& vertex4 = vertexBUFFER[v_INDEX + 3];

		vertex1.position = instance.ParticlePoint + ((-X - Y) * instance.size);
		vertex1.D_Color = instance.color;


		vertex2.position = instance.ParticlePoint + ((X - Y) * instance.size);
		vertex2.D_Color = instance.color;

		vertex3.position = instance.ParticlePoint + ((X + Y) * instance.size);
		vertex3.D_Color = instance.color;

		vertex4.position = instance.ParticlePoint + ((-X + Y) * instance.size);
		vertex4.D_Color = instance.color;
	}
}

void ParticleData::UpdateFrame(float time)
{
	
	for (unsigned int i = 0; i < ParticleBUFFER.size(); ++i)
	{
		Particle& instance = ParticleBUFFER[i];
		instance.P_age += time;
		//cout << instance.P_Lifetime;
		//cout << "time = " << time;
		//cout << instance.color.x;

		if (instance.P_age > instance.P_Lifetime)
		{
			if (ParticleEMIITER != NULL)
			{
				EmitSingleParticle(instance);
			}
			else
			{
				RandomParticles(instance);
			}

		}
		float AgeRatio = glm::saturate(instance.P_age / instance.P_Lifetime);
		instance.Speed += Force * time;
		instance.ParticlePoint += instance.Speed * time;
		instance.size = glm::lerp<float>(5.0f, 0.0f, AgeRatio);
		instance.color = DefaultCOLOR;
		//cout << instance.color.x;
	}
	CreateVertexBUFFER();
	
}

void ParticleData::RenderFrame()
{

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glMultMatrixf(glm::value_ptr(TransformationMatrix));
	
	

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(vertex), &(vertexBUFFER[0].position));
	glColorPointer(4, GL_FLOAT, sizeof(vertex), &(vertexBUFFER[0].D_Color));
	glDrawArrays(GL_QUADS, 0, vertexBUFFER.size());

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	
	if (ParticleEMIITER != NULL)
	{
		//std::cout << "worked";
		ParticleEMIITER->Render();
	}

	glPopMatrix();
	
}

void ParticleData::BufferResize(unsigned int Particle_count)
{
	ParticleBUFFER.resize(Particle_count, Particle());
	vertexBUFFER.resize(Particle_count * 4, vertex());
}