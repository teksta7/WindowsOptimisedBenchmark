#include "stdafx.h"
#include "Sphere.h"
#include <iostream>
#include <C:\SDK\Glut\glut.h>

Sphere::Sphere() :
MIN_RAD(0),
MAX_RAD(1),
MIN_Incline(0),
MAX_Incline(180),
MIN_Azi(0),
MAX_Azi(360),
MIN_Speed(10),
MAX_Speed(20),
MIN_Lifetime(3),
MAX_Lifetime(5),
Origin(0){}

void Sphere::Particle_Spawn(Particle& instance)
{
	float LifetimeMATH = (rand() / (float)RAND_MAX) * (MAX_Lifetime - MIN_Lifetime) + MIN_Lifetime;
	float InclineMATH = glm::radians((rand() / (float)RAND_MAX) * (MAX_Incline - MIN_Incline) + MIN_Incline);
	float AziMATH = glm::radians((rand() / (float)RAND_MAX) * (MAX_Azi - MIN_Azi) + MIN_Azi);
	float RadiusMATH = (rand() / (float)RAND_MAX) * (MAX_RAD - MIN_RAD) + MIN_RAD;
	float SpeedMATH = (rand() / (float)RAND_MAX) * (MAX_Speed - MIN_Speed) + MIN_Speed;
	
	float sinINCLINE = sinf(InclineMATH);

	float X = sinINCLINE * cosf(AziMATH);
	float Y = sinINCLINE * sinf(AziMATH);
	float Z = cosf(InclineMATH);

	glm::vec3 VECTOR(X, Y, Z);

	instance.ParticlePoint = (VECTOR*RadiusMATH) + Origin;
	instance.Speed = (VECTOR * SpeedMATH);
	instance.P_Lifetime = LifetimeMATH;
	instance.P_age = 0;


}

void Sphere::SphereRENDER(glm::vec4 color, float Radius)
{
	float X;
	float Y;
	float Z;
	float incline;
	float azimuth;
	//std::cout << "wo;
	glColor4fv(glm::value_ptr(color));
	glPointSize(2.0); //f
	glBegin(GL_POINTS);

	for (float AZI = MIN_Azi; AZI < MAX_Azi; AZI += 5.0f)
	{
		for (float inc = MIN_Incline; inc < MAX_Incline; inc += 5.0f)
		{
			incline = glm::radians(inc);
			azimuth = glm::radians(AZI);
			X = Radius *sinf(incline) * cosf(azimuth);
			Y = Radius *sinf(incline) * sinf(azimuth);
			Z = Radius *cosf(incline);

			glVertex3f(X, Y, Z);
		}
		incline = glm::radians(MAX_Incline);
		azimuth = glm::radians(AZI);

		X = Radius *sinf(incline) * cosf(azimuth);
		Y = Radius *sinf(incline) * sinf(azimuth);
		Z = Radius *cosf(incline);

		glVertex3f(X, Y, Z);
	}

	incline = glm::radians(MAX_Incline);
	azimuth = glm::radians(MAX_Azi);

	X = Radius *sinf(incline) * cosf(azimuth);
	Y = Radius *sinf(incline) * sinf(azimuth);
	Z = Radius *cosf(incline);

	glVertex3f(X, Y, Z);

	glEnd();
}

void Sphere::Render()
{
	glTranslatef(Origin.x, Origin.y, Origin.z);

	SphereRENDER(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), MAX_RAD);

	glTranslatef(-Origin.x, -Origin.y, -Origin.z);
}