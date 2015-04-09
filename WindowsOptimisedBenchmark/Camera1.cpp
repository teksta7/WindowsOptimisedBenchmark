#include "stdafx.h"
#include "Camera1.h"

Camera1::Camera1() :PIVOTorigin(0)
{

}

glm::vec3 Camera1::UnitProjection(glm::vec2 Position)
{
	float radius = std::fminf(ViewportWIDTH, ViewportHEIGHT);
	float X = (Position.x / radius)*2.0f;
	float Y = (Position.y / radius)*2.0f;
	float Z = 1.0f - (X * X) + (Y * Y);
	X -= 1.0f;
	Y -= 1.0f;
	Z = (Z > 0.0f) ? sqrtf(Z) : 0.0f;
	
	return glm::vec3(X, Y, Z);
}

void Camera1::UPDATE(float TIME)
{
	base::UPDATE(TIME);
}

void Camera1::TranslateP_X(float X)
{
	glm::quat rotation = glm::quat(glm::radians(rotate));
	PIVOTorigin += glm::vec3(X, 0, 0) * rotation;
}

void Camera1::TranslateP_Y(float Y)
{
	glm::quat rotation = glm::quat(glm::radians(rotate));
	PIVOTorigin += glm::vec3(0, Y, 0) * rotation;
}

void Camera1::TranslateP_Z(float Z)
{
	glm::quat rotation = glm::quat(glm::radians(rotate));
	PIVOTorigin += glm::vec3(0, 0, Z) * rotation;
}

void Camera1::ApplyPIVOT(const glm::vec3& PIVOT)
{
	PIVOTorigin = PIVOT;
}

glm::vec3 Camera1::getNEWpivot() const
{
	return PIVOTorigin;
}

void Camera1::transformVIEW()
{
	glTranslatef(0.0f, 0.0f, -translate.z);
	glRotatef(rotate.z, 0.0f, 0.0f, 1.0f);
	glRotatef(rotate.y, 0.0f, 1.0f, 0.0f);
	glRotatef(rotate.x, 1.0f, 0.0f, 0.0f);
	glTranslatef(-PIVOTorigin.x, -PIVOTorigin.y, -PIVOTorigin.z);
}