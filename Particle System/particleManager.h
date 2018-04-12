#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <string>
#include <iostream>
#include "particleClass.h"
#include <vector>
#include "particleSystem.h"

using namespace sf;
using namespace std;

class ParticleManager
{
public:
	void updateSys(float dt);
	void renderSystem(RenderWindow *window);
	void createSys(Vector2f, Texture*,float,float,float,int,float,float);
	void sysAddTotal();
	void sysSubTotal();
	int getTotalNum();
private:
	vector<ParticleSystem*> managerAry;
	int totalnum=0;
};
