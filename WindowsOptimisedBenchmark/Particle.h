#pragma once
//#define GLM_SWIZZLE_XYZW
#include <C:\SDK\glm\glm.hpp>
#include <C:\SDK\glm\gtc\type_ptr.hpp>
#include <C:\SDK\glm\gtc\swizzle.hpp>
#include <C:\SDK\glm\gtc\quaternion.hpp>
#include <C:\SDK\glm\gtx\vector_angle.hpp>
#include <C:\SDK\glm\gtx\compatibility.hpp>
#include <C:\SDK\glm\gtx\matrix_operation.hpp>
#include <C:\SDK\glm\gtx\transform.hpp>
#include <C:\SDK\glm\gtx\quaternion.hpp>
#include <C:\SDK\glm\gtx\euler_angles.hpp>
#include <C:\SDK\glm\gtx\norm.hpp>
#include <vector>


struct Particle
{
	glm::vec3 ParticlePoint; //Middle of particle
	glm::vec3 Speed; // Velocity of particle
	glm::vec4 color; // represents RGBA value for particle

	float size; //Particle Size
	float P_age; //Age of particle
	float P_Lifetime; //Lifetime that particle can exist for


	//Constructor
	Particle()
		: ParticlePoint(0),
		Speed(0),
		color(0),
		size(0),
		P_age(0),
		P_Lifetime(0)
	{}
};

//Create particle buffer
typedef std::vector<Particle> P_Buffer;
