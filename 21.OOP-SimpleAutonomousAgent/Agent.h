//	##########################################################
//	By Eugene Ch'ng | www.complexity.io | 2018
//	Email: genechng@gmail.com
//	----------------------------------------------------------
//	A C++ Object Oriented Class Integrating OpenGL
//
//  This example shows how to integrate OpenGL with Objects
//  encapsulating all internal functions, essentially creating
//  a pattern of an agent in Agent-based modelling systems
//
//	Autonomy is in the free roaming, and avoidance of boundaries
//	leaving the world
//
//  The Agent class prototype derives from Object
//  Prototype details are decoupled in Agent.h
//  Decoupling codes make it very easy to manage programmatically
//	##########################################################

#ifndef AGENT_H
#define AGENT_H

// we need the random function
#include <stdlib.h>     /* srand, rand */

#include "Grid.h"
#include "OGLUtil.h"
#include "Object.h"

/****************************** PROTOTYPES ******************************/
class Agent: public Object
{
protected:
  // Boundaries
  float _top; float _bottom; float _left; float _right;

  // movement variables
  float fAngle, fCurrAngle, fAngleSpeed, fMaxAngle, fScale;
	float fSpeed, fMaxSpeed;
	float fMovement, fFriction;

  // Matrix and Vector transforms
	Matrix4x4 matPos;  // position Matrix
	Matrix4x4 matRot;  // rotation matrix
	Vector3f 	vPos;    // position of the object

  // movement flags
	bool isForward, isBackward, isRight, isLeft, isMoving;

  // internal reference to global grid
  Grid _grid;

public:
  // ------------------- constructors destructors
  Agent();
  Agent(int _id, float origX, float origY, float origZ, float speed);
  ~Agent();

  // ------------------- update functions
  void render();
  void update();

  // ------------------- agent functions
  void autonomy();
  void getGrid(const Grid &grid);

  // ------------------- movement functions
  Vector3f getPosition();
  void rotateLeft(float fAngleSpeed);
  void rotateRight(float fAngleSpeed);
  void moveForward(float speed);
  void moveBackward(float speed);
  void stopForward();
  void stopBackward();
  void notMoving();

  // ------------------- visual representation function
  void DrawObject(float red, float green, float blue);
};

#endif
