#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <vector>
#include "behaviours.h"

using namespace sf;

class Linear_Beh:public Behaviours
{
public:
	float action_at_time(float,float,float,float);
private:
	float result;
};
