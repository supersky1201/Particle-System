#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <vector>
#include "particleClass.h"

using namespace sf;
using namespace std;
#define PI 3.1415926

class ParticleSystem
{
public:
	ParticleSystem(Vector2f, Texture*, float, float, float,int,float,float);
	void renderSys(RenderWindow *window);
	void updatePar(float dt);
	void numControl(float dt);
	void addTotal();
	void subTotal();
	int getParNum();

private:
	vector<ParticleClass*> particleAry;
	int total;
	Vector2f systemPos;
	Texture *systemTex;
	float systemSpeed;
	float systemA;
	float systemB;
	int type ;
	float startX;
	float finalX;
	int parNum;
};