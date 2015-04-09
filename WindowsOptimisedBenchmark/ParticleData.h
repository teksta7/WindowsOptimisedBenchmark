#pragma once
#include "particle.h"
#include "Emitter.h"
#include <C:\SDK\Glut\glut.h>

//class Emitter;
class CustomCamera;
class ParticleData
{
public:

	struct vertex
	{
		glm::vec3 position; // Position of vertex
		glm::vec4 D_Color; // Diffuse color of vertex

		vertex()
			:position(0),
			D_Color(1)
		{}

	};
	typedef std::vector<vertex> VertexBuffer;
	
	CustomCamera *BenchmarkCAM;
	Emitter *ParticleEMIITER;
	P_Buffer ParticleBUFFER;
	VertexBuffer vertexBUFFER;
	glm::mat4x4 TransformationMatrix;
	glm::vec3 Force;
	glm::vec4 DefaultCOLOR;


	ParticleData(unsigned int Particle_Count = 0);

	virtual void UpdateFrame(float time);
	virtual void RenderFrame();

	void ParticleSpawn();
	void Initialise_RAD_Particles();

	void CreateVertexBUFFER();
	void BufferResize(unsigned int Particle_count);

	void EmitterSpawn(Emitter * emitt);
	void RandomParticles(Particle& instance);
	void EmitSingleParticle(Particle& instance);
	void CameraSetup(CustomCamera * CAM);
	

};

