#include "stdafx.h"
#include "CustomCamera.h"

void CustomCamera::UPDATE(float TIME)
{

}

void CustomCamera::CreateViewport(float x, float y, float width, float height)
{
	ViewportX = x;
	ViewportY = y;
	ViewportWIDTH = width;
	ViewportHEIGHT = height;
}

void CustomCamera::CreateProjection(float FoV, float aspectRATIO, float camNEAR, float camFAR)
{
	FOV = FoV;
	AspectRatio = aspectRATIO;
	NearView = camNEAR;
	FarView = camFAR;
}

void CustomCamera::newPITCH(float PITCH)
{
	rotate.x += PITCH;
}

void CustomCamera::newYAW(float YAW)
{
	rotate.y += YAW;
}
void CustomCamera::newROLL(float ROLL)
{
	rotate.z += ROLL;
}

void CustomCamera::newROTATION(const glm::quat& ROTATION)
{
	glm::quat finalRotation = ROTATION * glm::quat(rotate);
	rotate = glm::eularAngles(finalRotation);
}

void CustomCamera::Xtranslate(float X)
{
	translate.x += X;
}

void CustomCamera::Ytranslate(float Y)
{
	translate.y += Y;
}

void CustomCamera::Ztranslate(float Z)
{
	translate.z += Z;
}

void CustomCamera::newTRANSLATE(const glm::vec3& translation)
{
	translate = translation;
}

void CustomCamera::updateROTATION(float PITCH, float YAW, float ROLL)
{
	rotate = glm::vec3(PITCH, YAW, ROLL);
}

void CustomCamera::updateROTATION(const glm::vec3& ROTATION)
{
	rotate = ROTATION;
}

glm::vec3 CustomCamera::getNEWtranslation()
{
	return translate;
}

glm::vec3 CustomCamera::getNEWrotation()
{
	return rotate;
}

void CustomCamera::CHANGEviewport()
{
	glViewport(ViewportX, ViewportY, ViewportWIDTH, ViewportHEIGHT);
}

void CustomCamera::CHANGEprojection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FOV, AspectRatio, NearView, FarView);
}

void CustomCamera::CHANGEtransformview()
{
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(translate.x, translate.y, translate.z);
	glRotatef(rotate.x, 1.0f, 0.0f, 0.0f);
	glRotatef(rotate.y, 0.0f, 1.0f, 0.0f);
	glRotatef(rotate.z, 0.0f, 0.0f, 1.0f);
	glRotatef(rotate.x, 1.0f, 0.0f, 0.0f);
}