#include "particleClass.h"
#include<cmath>

void ParticleClass::update(float dt)
{
	t = t + dt;
	if (size_at_time != NULL)
	{
		float r;
		r = size_at_time->action_at_time(start_b,t, lifetime,final_k);
		this->setScale ( Vector2f(r,r));
	}
	if (speed_at_time !=NULL)
	{
		float r;
		this->velocity = speed_at_time->action_at_time(start_b, t, lifetime, final_k);
	}
	this->setPosition(this->getPosition() + velocity*direction * dt);
	//lifetime=lifetime-dt;

	if (lifetime-t <= 0)
	{
		elapsed = true;
	}
}

float ParticleClass::randomFloat(float a, float b)
{
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

bool ParticleClass::isDead()
{
	return elapsed;
}

void ParticleClass::renderPar(RenderWindow* window)
{
	
		window->draw(*this);
	
}

void ParticleClass::setType(int i)
{
	if (i ==0)
	{
		size_at_time = new Linear_Beh;
	}
	if (i == 1)
	{
		speed_at_time = new Linear_Beh;
	}
}


ParticleClass::ParticleClass(Vector2f pos, Texture* tex, float speed, float a, float b, int i,float startX,float finalX)
{
	this->setPosition(pos);
	this->velocity = speed;
	this->angle = randomFloat(a, b);
	this->lifetime = randomFloat(5,10);
	float radian = PI * angle / 180;
	this->size_at_time = NULL;
	this->speed_at_time = NULL;
	this->direction = Vector2f(sin(radian), -cos(radian));
	this->elapsed = false;
	this->setSize (Vector2f(50, 50));
	//this->setFillColor(Color::Yellow);
	this->setTexture(tex);
	this->setType(i);
	this->t = 0;
	this->start_b = startX;
	this->final_k = finalX;
}



