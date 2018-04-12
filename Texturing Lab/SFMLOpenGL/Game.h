#ifndef GAME_H
#define GAME_H

#include <Debug.h>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Vector3D.h"
#include "Matrix3.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace std;
using namespace sf;
//using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	Clock clock;
	Time elapsed;

	Vector3D currentPosition[36];
	float rotationAngle = 0.0f;
	Matrix3 xRotation;//x axis rotation
	Matrix3 yRotation;//y axis rotation
	Matrix3 zRotation;//z axis rotation
	Vector3D activeTranslation{ 0,0,0 };
};

#endif