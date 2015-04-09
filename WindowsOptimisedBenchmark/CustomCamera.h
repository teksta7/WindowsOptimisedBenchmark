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
#include <C:\SDK\Glut\glut.h>
class CustomCamera
{
public:
		float ViewportX;
		float ViewportY;
		float ViewportWIDTH;
		float ViewportHEIGHT;

		float FOV;
		float AspectRatio;
		float NearView;
		float FarView;

		glm::vec3 translate;
		glm::vec3 rotate;

	CustomCamera() : translate(0)
	{

	}
	virtual ~CustomCamera()
	{

	};

	void CreateViewport(float x, float y, float width, float height);
	void CreateProjection(float FoV, float aspectRATIO, float camNEAR, float camFAR);
	void newPITCH(float pitch);
	void newYAW(float yaw);
	void newROLL(float roll);
	void newROTATION(const glm::quat& rotation);
	void Xtranslate(float X);
	void Ytranslate(float Y);
	void Ztranslate(float Z);
	void newTRANSLATE(const glm::vec3& translation);
	void updateROTATION(float PITCH, float YAW, float ROLL);
	void updateROTATION(const glm::vec3& Rotate);

	glm::vec3 getNEWtranslation();
	glm::vec3 getNEWrotation(); //may need const at end

	virtual void UPDATE(float TIME) = 0;
	virtual void CHANGEviewport();
	virtual void CHANGEprojection();
	virtual void CHANGEtransformview();


};

