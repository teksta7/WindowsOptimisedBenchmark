#pragma once
#include "CustomCamera.h"

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
class Camera1 : public CustomCamera
{
public:
	typedef CustomCamera base;

	Camera1();

	glm::vec3 PIVOTorigin;

	virtual void UPDATE(float TIME);
	virtual void transformVIEW();

	glm::vec3 UnitProjection(glm::vec2 Postion);

	void TranslateP_X(float X);
	void TranslateP_Y(float Y);
	void TranslateP_Z(float Z);

	void ApplyPIVOT(const glm::vec3& PIVOT);
	glm::vec3 getNEWpivot() const;


};

