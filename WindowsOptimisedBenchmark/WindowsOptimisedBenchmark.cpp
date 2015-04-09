// WindowsOptimisedBenchmark.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <C:\SDK\Glut\glut.h>

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

#include "Emitter.h"
#include "Particle.h"
#include "ParticleData.h"
#include "Sphere.h"
#include "Camera1.h"

Camera1 Benchmark;
Sphere Particles;
ParticleData Particle_Count(1000);

glm::vec3 DefaultCAMpos(0, 0, 100);
glm::vec3 DefaultCAMrot(40, 0, 0);
glm::vec3 DefaultCAMpiv(0, 0, 0);


using namespace std;

//Track mouse inputs
bool LeftMousePressed = false;
bool RightMousePressed = false;

//Window Size of the benchmark
const int Window_W = 800;
const int Window_H = 600;

//Will be used to create the window
int GLUTWINDOW;

int fps = 0;
int framerate;
int previous;

float Time = 0.01;
float PreviousTime = 0;
float timestep = 0.33333f;

bool update = true;
//Location Postion of mouse
glm::vec2 Mouse_CurrentLOC = glm::vec2(0);
glm::vec2(Mouse_PreviousLOC) = glm::vec2(0);
glm::vec2(Mouse_NewLOC) = glm::vec2(0);

//Camera Settings
glm::vec3(TranslateCAM)(0, 0, 0);
glm::vec3(RotateCAM)(0, 0, 0);
glm::vec3(PivotCAM)(0, 0, 0);



void Axis(glm::vec3 Move = glm::vec3(0))
{
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	//glDisable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(Move.x, Move.y, Move.z);
	//glScalef(Scale, Scale, Scale);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	//glutWireCube(20);

	//glBegin(GL_LINES);
	//{
		///glColor3f(1.0f, 0.0f, 0.0f);
		//glVertex3f(0.0f, 0.0f, 0.0);
		//glVertex3f(1.0f, 0.0f, 0.0f);

		//glColor3f(0.0f, 1.0f, 0.0f);
		//glVertex3f(0.0f, 0.0f, 0.0f);
		//glVertex3f(0.0f, 1.0f, 0.0f);

		//glColor3f(0.0f, 0.0f, 1.0f);
		//glVertex3f(0.0f, 0.0f, 0.0f);
		//glVertex3f(0.0f, 0.0f, 1.0f);


	//}
	//glEnd();

	glPopMatrix();
	glPopAttrib();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Benchmark.transformVIEW();

	//glLoadIdentity();
	// Set the camera
	//gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
	Axis(PivotCAM);

	Particle_Count.RenderFrame();
	//std::cout << "Done";

	glutSwapBuffers();
	glutPostRedisplay();

}

void FPS()
{
	//  Increase frame count
	++fps;

	//  Get the number of milliseconds since glutInit called
	//  (or first call to glutGet(GLUT ELAPSED TIME)).
	int current = glutGet(GLUT_ELAPSED_TIME);

	//  Calculate time passed
	int timeInterval = current - previous;

	if (timeInterval > 1000)
	{
		//  calculate the number of frames per second
		framerate = fps / (timeInterval / 1000.0f);

		//  Set time
		previous = current;

		//  Reset frame count
		fps = 0;
	}
	cout << "FPS::" << framerate << endl;
}

float timer()
{
	float fCurrentTime = std::clock() / (float)CLOCKS_PER_SEC;
	float fDeltaTime = fCurrentTime - PreviousTime;
	PreviousTime = fCurrentTime;

	// Clamp to the max time step
	fDeltaTime = std::fmin(fDeltaTime, timestep);

	return fDeltaTime;
}



void Idle()
{
	//Time = timer();
	//Time = 0.0003 + Time;
	//cout << Time;
	if (update)
	{
		Particle_Count.UpdateFrame(Time);
		 
	}
	else
	{
		Particle_Count.CreateVertexBUFFER();
	}
	
	
	FPS();
	glutPostRedisplay();
	

}

void Mouse(int click, int clicked, int X, int Y)
{

}

void Motion(int X, int Y)
{

}

void Reshape(int width, int height)
{
	Benchmark.CreateViewport(0, 0, width, height);
	Benchmark.CHANGEviewport();

	Benchmark.CreateProjection(60.f, width / (float)height, 0.1f, 1000.0f);
	Benchmark.CHANGEprojection();
	glutPostRedisplay();

}


void Keyboard(unsigned char c, int X, int Y)
{

}

void Initialise(int argc, char* argv[])
{
	//Initialise OpenGL/GLUT
	//*************************************
	cout << "OpenGL Initialisation" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(Window_W, Window_H);
	GLUTWINDOW = glutCreateWindow("Intel Optimised Windows Benchmark");

	// Register GLUT callbacks
	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	//glutSpecialFunc(Special);
	glutKeyboardFunc(Keyboard);
	glutReshapeFunc(Reshape);

	//Setup Initial state of scene
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	glShadeModel(GL_SMOOTH);
	cout << "Completed" << endl;;
	//*************************************
}

int main(int argc, char* argv[])
{
	Initialise(argc,argv);
	Benchmark.newTRANSLATE(DefaultCAMpos);
	Benchmark.updateROTATION(DefaultCAMrot);
	Benchmark.ApplyPIVOT(DefaultCAMpiv);
	
	//Particle_Count.EmitterSpawn(&Particles);
	//for (unsigned int i = 0; i < Particle_Count.ParticleBUFFER.size(); ++i)
	//{
	//	Particle_Count.ParticleSpawn(Particle_Count.ParticleBUFFER[i]);
	//}
	Particle_Count.CameraSetup(&Benchmark);
	Particle_Count.EmitterSpawn(&Particles);
	Particle_Count.ParticleSpawn();
	//Particle_Count.CameraSetup(Benchmark);
	//Particle_Count.ParticleSpawn(&Particles);
	//Particle_Count.EmitterSpawn;

	glutMainLoop();

	
	return 0;
}

