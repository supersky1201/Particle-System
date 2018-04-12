#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <vector>
#include "linear_Beh.h"

using namespace sf;
#define PI 3.1415926

class ParticleClass : public RectangleShape
{
public:
	void update(float dt);
	float randomFloat(float,float);
	ParticleClass(Vector2f pos, Texture* tex, float speed, float a, float b,int i,float,float);
	bool isDead();
	void renderPar(RenderWindow *window);
	void setType(int);


private:
	float velocity;
	float angle;
	float lifetime;
	Vector2f pos;
	Vector2f direction;
	bool elapsed;
	Behaviours* size_at_time;
	Behaviours* speed_at_time;
	float start_b;
	float final_k;	
	float t;
};