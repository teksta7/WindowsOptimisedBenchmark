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

using namespace std;

//Track mouse inputs
bool LeftMousePressed = false;
bool RightMousePressed = false;

//Window Size of the benchmark
const int Window_W = 800;
const int Window_H = 600;

//Will be used to create the window
int GLUTWINDOW;

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
	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_LINES);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0);
		glVertex3f(1.0f, 0.0f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 1.0f);


	}
	glEnd();

	glPopMatrix();
	glPopAttrib();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity();


	//Axis(PivotCAM);


	glutSwapBuffers();
	glutPostRedisplay();

}

void Idle()
{
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
	glutMainLoop();

	
	return 0;
}

